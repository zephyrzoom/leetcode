/**
 * 这道题用到了动态规划，将问题分解为子问题，逐一解决。
 * 将s1和s2进行对应位置的划分，比较左右两端的划分是否还是scramble。
 * 比如：“abc”和“bca”，从第一个位置开始划分分为a|bc和b|ca，也就是解决自问题：isScramble("a","b")和isScramble("bc","ca")的问题。
 * 一种划分有两种可能的符合情况，另一种是a|bc和bc|a，与上面的方式类似。
 * 计算完这种划分，如果不匹配，就再从第二个位置划分，如ab|c和bc|a；ab|c和b|ca，这两种可能情况。
 */
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Solution {
private:
    unordered_map<string, bool> scrambles;
public:
    bool isScramble(string s1, string s2) {
        const int len = s1.size();
        if (len <= 1) {
            return s1 == s2;
        } else {
            bool isScramblePair = false;
            if (scrambles.count(s1+s2)) {
                return scrambles[s1+s2];
            }
            if (s1 == s2) {
                isScramblePair = true;
            } else {
                for (size_t i = 1; i < len && !isScramblePair; i++) {
                    isScramblePair |= isScramble(s1.substr(0, i), s2.substr(0, i))
                    && isScramble(s1.substr(i, len), s2.substr(i, len));
                    isScramblePair |= isScramble(s1.substr(0, i), s2.substr(len-i, len))
                    && isScramble(s1.substr(i, len), s2.substr(0, len-i));
                }
            }
            return scrambles[s1+s2] = isScramblePair;
        }
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    string s1 = "abc";
    string s2 = "bca";
    s.isScramble(s1, s2);
    return 0;
}
