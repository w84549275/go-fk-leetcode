#include <stdio.h>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 0)
            return true;
        if (s.size() % 2 == 1)
            return false;
        
        stack<char> st;
        for (char c : s) {
            if (c == '(') 
                st.push(')');

            if (c == '{') 
                st.push('}');

            if (c == '[') 
                st.push(']');

            if (c == ')') {
                if (!st.empty() && st.top() == ')')
                    st.pop();
                else
                    return false;
            }
            if (c == '}') {
                if (!st.empty() && st.top() == '}')
                    st.pop();
                else
                    return false;
            }
            if (c == ']') {
                if (!st.empty() && st.top() == ']')
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty();
    }
};