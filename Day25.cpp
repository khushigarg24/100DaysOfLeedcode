//101. Symmetric Tree
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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;

        queue<TreeNode*> leftQueue, rightQueue;
        leftQueue.push(root->left);
        rightQueue.push(root->right);

        while (!leftQueue.empty() && !rightQueue.empty()) {
            TreeNode* leftNode = leftQueue.front();
            leftQueue.pop();
            TreeNode* rightNode = rightQueue.front();
            rightQueue.pop();

            if (leftNode == nullptr && rightNode == nullptr)
                continue;
            if (leftNode == nullptr || rightNode == nullptr)
                return false;
            if (leftNode->val != rightNode->val)
                return false;
            if (leftNode != nullptr) {
                leftQueue.push(leftNode->left);
                rightQueue.push(rightNode->right);
            }
            if (rightNode != nullptr) {
                leftQueue.push(leftNode->right);
                rightQueue.push(rightNode->left);
            }
        }
        return true;
    }
};

//99. Recover Binary Search Tree
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
void marktree(TreeNode* root,TreeNode*&first,TreeNode*&prev,TreeNode* &last){
    if(!root)return;
     marktree(root->left,first,prev,last);
    //  if prev is not null
     if(prev){
        if(root->val<prev->val){
            if(!first){
                first=prev;
            }
            last=root;
        }
     }
     prev=root;
      marktree(root->right,first,prev,last);
}
    void recoverTree(TreeNode* root) {
        TreeNode *first=NULL,*prev=NULL,*last=NULL;
        marktree(root,first,prev,last);
        swap(first->val,last->val);
        return;
    }
};