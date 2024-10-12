//1161. Maximum Level Sum of a Binary Tree
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
    public int maxLevelSum(TreeNode root) {
        if(root==null){
            return 0;
        }
        Queue<TreeNode>q = new LinkedList<>();
        q.offer(root);

        int level=0, ans=0, max=Integer.MIN_VALUE;
        while(!q.isEmpty()){
            level++;
            int sum=0;
            for(int i=q.size();i>0;i--){
                TreeNode node=q.poll();
                sum+=node.val;
                if(node.left!=null){
                    q.offer(node.left);
                }
                if(node.right!=null){
                    q.offer(node.right);
                }
            }
            if(sum>max){
                max=sum;
                ans=level;
            }
        }
        return ans;
    }
}


//450. Delete Node in a BST
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
    public TreeNode deleteNode(TreeNode root, int key) {
        if(root==null){
            return root;
        }
        if(root.val>key)
        root.left=deleteNode(root.left,key);

        else if(root.val<key)
        root.right=deleteNode(root.right,key);

        else{
            if(root.left==null)return root.right;
            if(root.right==null)return root.left;

            // if key is having both left and right child
            root.val=successor(root.right);
            root.right=deleteNode(root.right,root.val);
        }
        return root;
    }
    private int successor(TreeNode root){
        if(root.left==null)
            return root.val;
            return successor(root.left);
        
    }
}