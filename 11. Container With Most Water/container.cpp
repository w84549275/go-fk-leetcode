#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        // two pointers
        int low = 0, high = height.size() - 1;
        while (low < high){
            if (height[low] < height[high]){
                ans = max(ans, height[low] * (high - low));
                low++;
            }
            else{
                ans = ans = max(ans, height[high] * (high - low));
                high--;
            }
        }
        return ans;
    }
};