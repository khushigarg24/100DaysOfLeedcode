//530. Minimum Absolute Difference in BST
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    int prev = INT_MAX;
    int ans = INT_MAX;

public:
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return ans;
    }

    void inorder(TreeNode* root) {
        if (root->left != NULL) {
            inorder(root->left);
        }
        ans=min(ans,abs(root->val-prev));
        prev=root->val;
        if(root->right!=NULL){
            inorder(root->right);
        }
    }
};


//540. Single Element in a Sorted Array
class Solution {
    public int singleNonDuplicate(int[] nums) {
        int ans=0;
        for(int i=0;i<nums.length;i++){
            ans=ans^nums[i];
        }
        return ans;
    }
}