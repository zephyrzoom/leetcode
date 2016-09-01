#include <vector>

using std::vector;

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> permutations;
        if (nums.size() == 1) {
            permutations.push_back(nums);
        } else {
            for (int n = 0; n < nums.size(); n++) {
                vector<int> tmp = nums;
                tmp.erase(tmp.begin() + n);
                vector<vector<int>> withoutS = permute(tmp);
                for (auto i : withoutS) {
                    vector<int> v;
                    v.push_back(nums[n]);
                    v.insert(v.end(),i.begin(), i.end());
                    permutations.push_back(v);
                }
            }
        }
        return permutations;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    vector<int> nums = {1, 2};
    s.permute(nums);
    return 0;
}
