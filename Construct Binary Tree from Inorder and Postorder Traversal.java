import java.util.*;
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    Map<Integer,Integer> map = new HashMap<Integer,Integer>();
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        int n = inorder.length;
        for(int i=0;i<n;i++){
            map.put(inorder[i],i);
        }
        return construct(inorder,postorder,0,n-1,n-1);
    }
    public TreeNode construct(int[] inorder,int[] postorder,int start,int end,int index){
        if(start>end){
            return null;
        }
        TreeNode root = new TreeNode(postorder[index]);
        int idx = map.get(postorder[index]);
        root.right = construct(inorder,postorder,idx+1,end,index-1);
        root.left = construct(inorder,postorder,start,idx-1,index-end+idx-1);
        return root;
    }
}