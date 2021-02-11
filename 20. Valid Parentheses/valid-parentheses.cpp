#include <stdio.h>
#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 0)
            return true;
        if (s.size() % 2 == 1)
            return false;

        stack<char> st;
        unordered_map<char, char> map = {{'(', ')'}, {'{', '}'}, {'[', ']'}};
        for (char c : s) {
            if (st.empty())
                st.push(c);
            else {
                if (c == map[st.top()])
                    st.pop();
                else
                    st.push(c);
            }
        }
        return st.empty();
    }
};