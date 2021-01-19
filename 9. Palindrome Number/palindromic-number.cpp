class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
        int num = x;
        long cur = 0;
        while (num != 0) {
            cur = cur * 10 + num % 10;
            num /= 10;
        }
        return cur == x;
    }
};