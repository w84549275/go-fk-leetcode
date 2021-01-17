#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.size() <= numRows){
            return s;
        }

        vector<string> rows(s.size());
        
        int flag = -1;
        int index = 0;
        for (int i = 0; i < s.size(); i++) {
            rows[index] += s[i];
            if (index == 0 || index == numRows - 1) {
                flag = -flag;
            }
            index += flag;
        }

        string result;
        for (int i = 0; i < s.size(); i++){
            result += rows[i];
        }
        
        return result;
    }
};