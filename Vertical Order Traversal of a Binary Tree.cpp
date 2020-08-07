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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
       vector<vector<int>> ans;
       if(root==NULL){
           return ans;
       }
       queue<pair<TreeNode*,int>> q;
       map<int,vector<int>> mp1,mp2;
       q.push({root,0});
       while(!q.empty()){
          int sz = q.size();
           while(sz--){
               pair<TreeNode*,int> pi = q.front();
               q.pop();
               mp2[pi.second].push_back(pi.first->val);
               if(pi.first->left!=NULL){
                   q.push({pi.first->left,pi.second-1});
               }
               if(pi.first->right!=NULL){
                   q.push({pi.first->right,pi.second+1});
               }
           }
           for(auto pi:mp2){
               if(pi.second.size()>1){
                   sort(pi.second.begin(),pi.second.end());
               }
               for(int val:pi.second){
                   mp1[pi.first].push_back(val);
               }
           }
           mp2.clear();
           
       }
       for(auto p:mp1){
           ans.push_back(p.second);
       }
       return ans;
    }
  
};