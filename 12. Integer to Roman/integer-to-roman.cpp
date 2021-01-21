#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<int> vals = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> romans = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string ans = "";
        for (int i = 0; i < 13; i++) {
            while (num >= vals[i]) {
                ans += romans[i];
                num -= vals[i];
            }
        }
        return ans;
    }
};