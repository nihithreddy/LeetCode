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
    TreeNode* inorderpredecessor(TreeNode* root){
        while(root->right){
            root = root->right;
        }
        return root;
    }
    TreeNode* inordersucessor(TreeNode* root){
        while(root->left){
            root = root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
       if(root==NULL) return root;
       else if(key > root->val) root->right = deleteNode(root->right,key);
       else if(key < root->val) root->left = deleteNode(root->left,key);
       else{
           if(!root->left && !root->right) root = nullptr;
           else if(root->left){
               TreeNode* temp = inorderpredecessor(root->left);
               root->val = temp->val;
               root->left = deleteNode(root->left,root->val);
           }
           else{
               TreeNode* temp = inordersucessor(root->right);
               root->val = temp->val;
               root->right = deleteNode(root->right,root->val);
           }
       }
        return root;
    }
};