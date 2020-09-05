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
    void inorder(TreeNode* root,vector<int>& nodes){
        if(root == NULL) return;
        inorder(root->left,nodes);
        nodes.push_back(root->val);
        inorder(root->right,nodes);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
          vector<int> first_tree,second_tree,ans;
          inorder(root1,first_tree);
          inorder(root2,second_tree);
          int n = (int)first_tree.size();
          int m = (int)second_tree.size();
          int i=0,j=0,k=0;
          ans.resize(n+m);
          while(i<n && j<m){
              if(first_tree.at(i) < second_tree.at(j)){
                  ans.at(k) = first_tree.at(i);
                  i++;
                  k++;
              }
              else{
                  ans.at(k) = second_tree.at(j);
                  j++;
                  k++;
              }
          }
        while(i<n){
             ans.at(k) = first_tree.at(i);
             i++;
             k++;
        }
        while(j<m){
            ans.at(k) = second_tree.at(j);
            j++;
            k++;
        }
        return ans;
    } 
};