//96. Unique Binary Search Trees
class Solution {
public:
    int numTrees(int n) {
        int num[n + 1];
        num[0] = num[1] = 1;

        for (int i = 2; i <= n; i++) {
            num[i] = 0;
            for (int j = 0; j < i; j++) {
                num[i]+=num[j]*num[i-j-1];
            }
        }
        return num[n];
    }
};

//98. Validate Binary Search Tree
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
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
    bool isValidBST(TreeNode* root, long minVal, long maxVal) {
        if (root == NULL) {
            return true;
        }
        if (root->val >= maxVal || root->val <= minVal) {
            return false;
        }
        return isValidBST(root->left, minVal, root->val) &&
               isValidBST(root->right, root->val, maxVal);
    }
};