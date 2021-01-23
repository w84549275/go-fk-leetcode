#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        // compare every str's first letter
        for (int i = 0; i < strs[0].size(); i++) {
            char curr = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != curr || i == strs[j].size()) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};