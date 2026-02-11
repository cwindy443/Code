/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        else if(x == 0) return true;
        else {
            int pre = x; int y = 0;
            while(x) {
                y = y * 10 + (x % 10); x /= 10;
            }
            return y == pre;
        }
    }
};
// @lc code=end

