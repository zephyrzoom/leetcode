#include <string>
using std::string;
class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            string sub;
            int max = 0;
            int length = 0;
            for (auto i : s) {
                int start = sub.find(i);
                if (start != string::npos) {
                    sub = sub.substr(start + 1);
                    length = sub.size();
                    sub += i;
                    length++;
                } else {
                    sub += i;
                    length++;
                    if (length > max) {
                        max = length;
                    }
                }
            }
            return max;
        }
};

int main() {
    Solution s;
    int max = s.lengthOfLongestSubstring("aab");
    return 0;
}
