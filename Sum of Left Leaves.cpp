#include<bits/stdc++.h>
using namespace std;
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
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root,0);
    }
    int solve(TreeNode* root,int dir){
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL&&root->right==NULL&&dir==1){
            return root->val;
        }
        int leftSum = solve(root->left,1);
        int rightSum = solve(root->right,2);
        return leftSum + rightSum;
    }
};
