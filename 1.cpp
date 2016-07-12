/*
 * @author 707<707472783@qq.com>
 * Question:Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 */
#include <iostream>
#include <vector>
using std::vector;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target);
    int findPos(vector<int>& nums, int num, int exist);
};

vector<int> Solution::twoSum(vector<int>& nums, int target) {
    vector<int> result;
    for (size_t i = 0; i < nums.size(); i++) {
        int anotherPos = findPos(nums, target - nums[i], i);
        if (anotherPos >= 0) {
            result.push_back(i);
            result.push_back(anotherPos);
            break;
        }
    }
    return result;
}

int Solution::findPos(vector<int>& nums, int num, int exist) {
    for (size_t i = 0; i < nums.size(); i++) {
        if (nums[i] == num) {
            if (i == exist) {
                continue;
            }
            return i;
        }
    }
    return -1;
}

int main() {
    Solution s;
    vector<int> v = {-1,-2,-3,-4,-5};
    vector<int> r = s.twoSum(v, -8);
    for (auto i : r) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
