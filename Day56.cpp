//889. Construct Binary Tree from Preorder and Postorder Traversal
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
    int preIdx = 0;
    int postIdx = 0;
    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {
        // create root tree
        TreeNode* root = new TreeNode(preorder[preIdx++]);

        if (root->val != postorder[postIdx]) {
            root->left = constructFromPrePost(preorder, postorder);
        }

        if (root->val != postorder[postIdx]) {
            root->right = constructFromPrePost(preorder, postorder);
        }
        postIdx++;
        return root;
    }
};


//901. Online Stock Span
#include <stack>
#include <vector>

class StockSpanner {
public:
    stack<pair<int, int>> stack;

    StockSpanner() {}

    int next(int price) {
        int ans = 1;
        while (!stack.empty() && stack.top().first <= price) {
            ans += stack.top().second;
            stack.pop();
        }
        stack.push({price,   ans});
        return ans;
         
    }
};