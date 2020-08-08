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
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
 
    int pathSum(TreeNode* root, int sum) {
        if(!root){
            return 0;
        }
        else{
            return findSum(root,sum)+pathSum(root->left,sum)+pathSum(root->right,sum);
        }
    }
    int findSum(TreeNode* root,int sum){
       if(!root){
           return 0;
       }
       else{
           return (root->val==sum)+findSum(root->left,sum-root->val)+findSum(root->right,sum-root->val);
       }
        
    }
    
};