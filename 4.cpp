#include <vector>
using std::vector;
class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            double mid1;
            double mid2;
            while (nums1.size() + nums2.size() > 4) {
                mid1 = getMid(nums1);
                mid2 = getMid(nums2);
                if (mid1 == mid2) {
                    return mid1;
                } else if (mid1 < mid2) {
                    nums1.erase(nums1.begin(), nums1.begin() + nums1.size() / 2);
                    nums2.erase(nums2.begin() + (nums2.size() + 1) / 2, nums2.end());
                } else {
                    nums2.erase(nums2.begin(), nums2.begin() + nums2.size() / 2);
                    nums1.erase(nums1.begin() + (nums1.size() + 1) / 2, nums1.end());
                }
            }
            vector<int> mix;
            for (auto i = nums1.begin(), j = nums2.begin(); i != nums1.end() || j != nums2.end();) {
                if (*i < *j) {
                    if (i == nums1.end()) {
                        for (auto k = j; k != nums2.end(); k++) {
                            mix.push_back(*k);
                        }
                        break;
                    } else {
                        mix.push_back(*i);
                        i++;
                    }
                } else {
                    if (j == nums2.end()) {
                        for (auto k = i; k != nums1.end(); k++) {
                            mix.push_back(*k);
                        }
                        break;
                    } else {
                        mix.push_back(*j);
                        j++;
                    }
                }
            }
            return getMid(mix);
        }

        double getMid(vector<int>& nums);
};
double Solution::getMid(vector<int>& nums) {
    double mid;
    if (nums.size() % 2 == 0) {
        mid = (nums[nums.size() / 2 - 1] + nums[nums.size() / 2]) / 2.0;
    } else {
        mid = nums[nums.size() / 2];
    }
    return mid;
}

int main() {
    Solution s;
    vector<int> nums1 = { 1, 5, 6, 7 };
    vector<int> nums2 = { 2, 3, 4 };
    double r = s.findMedianSortedArrays(nums1, nums2);
    return 0;
}
