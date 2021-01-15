#include <stdlib.h>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string slide_window = "";
        int ans = 0;
        for (int i = 0; i < s.size(); i++){
            for (int j = 0; j < slide_window.size(); j++){
                if (s[i] == slide_window[j]) 
                    slide_window.erase(0, j + 1);
            }
            slide_window += s[i];
            ans = max(ans, int(slide_window.size()));
        }
        return ans;
    }
};