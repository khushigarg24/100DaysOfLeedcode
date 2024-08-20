//189. Rotate Array
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp(nums.size());

        for(int i=0;i<nums.size();i++){
            temp[(i+k)%nums.size()]=nums[i];
        }

        nums=temp;
    }
};

//173. Binary Search Tree Iterator
<<<<<<< HEAD
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
=======

>>>>>>> origin/master
class BSTIterator {
    Stack<TreeNode> stack;

    public BSTIterator(TreeNode root) {
        stack = new Stack<>();
        // insert left boundary
        TreeNode node = root;
        while (node != null) {
            stack.push(node);
            node = node.left;
        }
        // pehle saare leftdaldiye

    }

    public int next() {
        TreeNode node = stack.pop();
        int val = node.val;
        node = node.right; // right dalke saare left daldiye uske
        while (node != null) {
            stack.push(node);
            node = node.left;
        }
        return val;
    }

    public boolean hasNext() {
        return !stack.isEmpty();
    }
}
<<<<<<< HEAD

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
=======
>>>>>>> origin/master
