#include <stdlib.h>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> romans = {{"M", 1000}, {"D", 500}, {"C", 100}, {"L", 50}, {"X", 10}, {"V", 5}, {"I", 1}};
        int ans = 0, last_int = 0, num = 0;
        for (int i = 0; i < s.size(); i++) {
            // traverse s in backward order
            string ch = s.substr(s.size() - (i + 1), 1);
            num = romans[ch];
            if (num < last_int) {
                // the situation that s has a substr "IV"
                // we need to subtract 1 i.e. char "I" because "V" has beed added
                ans -= num;
            }
            else {
                ans += num;
            }
            last_int = num;
        }
        return ans;
    }
};