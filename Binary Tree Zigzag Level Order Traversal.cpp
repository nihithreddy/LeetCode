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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        if(root == NULL){
            return vec;
        }
        stack<TreeNode*> st1,st2;
        st1.push(root);
        while(!(st1.empty()&&st2.empty())){
            vector<int> nodes;
            while(!st1.empty()){
                TreeNode* node = st1.top();
                st1.pop();
                nodes.push_back(node->val);
                if(node->left!=NULL){
                    st2.push(node->left);
                }
                if(node->right!=NULL){
                    st2.push(node->right);
                }
            }
            if(!nodes.empty()){
            vec.push_back(nodes);
            }
            nodes.clear();
            while(!st2.empty()){
                TreeNode* node = st2.top();
                st2.pop();
                nodes.push_back(node->val);
                if(node->right!=NULL){
                    st1.push(node->right);
                }
                if(node->left!=NULL){
                    st1.push(node->left);
                }
            }
            if(!nodes.empty()){
            vec.push_back(nodes);
            }
        }
     return vec;
    }
};