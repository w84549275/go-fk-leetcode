#include <stdlib.h>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    int length_of_int(int x) {
        int length = 0;
        while (x != 0) {
            length++;
            x /= 10;
        }
        return length;
    }

    int reverse(int x) {
        long ans = 0;
        int length = length_of_int(x);
        vector<int> figure(length);
        for (int i = 0; i < length; i++) {
            figure[i] = x % 10;
            x /= 10;
        }
        for (int j = 0; j < figure.size(); j++){
            ans += figure[j] * pow(10, length - 1);
            // ans goes outside of the signed 32-bit integer range
            if (ans < -2147483648 || ans > 2147483647){
                return 0;
            }
            length--;
        }
        return (int)ans;
    }
};

int main(){
    Solution a;
    cout<<a.length_of_int(-12)<<endl;
    cout<<a.reverse(1919810)<<endl;
    cout<<a.reverse(-12)<<endl;
    cout<<a.reverse(-12340)<<endl;
    return 0;
}