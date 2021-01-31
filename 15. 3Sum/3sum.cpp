#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) { // nums = [-1,0,1,2,-1,-4]
        vector<vector<int>> ans;
        if (nums.size() < 3) {
            return ans;
        }
        // sort the vector
        sort(nums.begin(), nums.end());
        
        // triple pointers
        for (int k = 0; k < nums.size(); k++){
            if (nums[k] > 0) {
                break;
            }
            if (k > 0 && nums[k] == nums[k - 1]) {
                continue;
            }
            
            int i = k + 1;
            int j = nums.size() - 1;
            while (i < j) {
                if (nums[k] + nums[i] + nums[j] == 0) {
                    while (i < j && nums[i] == nums[i + 1]) {
                        i++;
                    }
                    while (i < j && nums[j] == nums[j - 1]) {
                        j--;
                    }
                    ans.push_back({nums[k], nums[i], nums[j]});
                    i++;
                    j--;
                }
                else if (nums[k] + nums[i] + nums[j] < 0) {
                    i++;
                }
                else {
                    j--;
                }
            }
        }
        return ans;
    }
};