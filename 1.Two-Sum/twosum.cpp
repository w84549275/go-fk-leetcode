#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> visited;
        vector<int> ans;
        int num1, num2;
        bool flag = false;
        for (int i = 0; i < nums.size(); i++){
            /* traverse the vector */
            int rest = target - nums[i];
            for (int j = 0; j < visited.size(); j++){
                if (rest == visited[j]){
                    num1 = rest;
                    num2 = nums[i];
                    flag = true;
                }
            }
            if (flag) break;
            visited.push_back(nums[i]);
        }
        for (int i = 0; i < nums.size(); i++){
            if (num1 == nums[i]){
                ans.push_back(i);
                break;
            }
        }
        for (int i = 0; i < nums.size(); i++){
            if (num2 == nums[i] && i != ans[0]){
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};