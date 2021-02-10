/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <stdio.h>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    vector<TreeNode*> generateTreesHelper(int start, int end) {
        vector<TreeNode*> ret;
        if (start > end) {
            ret.push_back(nullptr);
        }

        // let i be the root, recursively constructing all BSTs
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left_subtree = generateTreesHelper(start, i - 1);
            vector<TreeNode*> right_subtree = generateTreesHelper(i + 1, end);
            for (auto &l : left_subtree) {
                for (auto &r : right_subtree) {
                    TreeNode *node = new TreeNode(i, l, r);
                    ret.push_back(node);
                }
            }
        }
        return ret;
    }

    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ans;
        ans = generateTreesHelper(1, n);
        return ans;
    }
};