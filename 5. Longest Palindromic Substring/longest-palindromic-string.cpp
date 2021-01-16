#include <stdlib.h>
#include <string>
using namespace std;

class Solution {
public:
    int centerSpreadMethod(string s, int center) {
        int length_of_palindrome = 0;
        int i = center - 1;
        int j = center + 1;
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            --i;
            ++j;
            ++length_of_palindrome;
        };
        return length_of_palindrome;
    }
    string pretreat_for_string(string s) {
        string pretreated_str = "#";
        // we want to transform an original str such as "aabaab" to "#a#a#b#a#a#b#"
        for (int i = 0; i < s.size(); i++) {
            pretreated_str += s[i];
            pretreated_str += "#";
        }
        return pretreated_str;
    }
    
    //implementing Manacher algorithm
    string longestPalindrome(string s) {
        // special case that s = "" or s = "a"
        if (s.size() <= 1)
            return s;
        
        string str = pretreat_for_string(s);
        int max_length = 1;
        int start = 0;
        for (int i = 0; i < str.size(); i++){
            int curr_length = centerSpreadMethod(str, i);
            if (curr_length > max_length) {
                max_length =  curr_length;
                start = (i - max_length) / 2;
            }
        }
        return s.substr(start, max_length);
    }
};