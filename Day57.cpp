//933. Number of Recent Calls
class RecentCounter {
public:
    RecentCounter() {
        
    }
    queue<int> q;
    int ping(int t) {
        if(q.empty()){
            q.push(t);
        }
        else{
            while(!q.empty() && q.front()<(t-3000)){
                q.pop();
            }
            q.push(t);
        }
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */

//938. Range Sum of BST

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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) {
            return 0;
        }
        if (root->val >= low && root->val <= high) {
          return  root->val + rangeSumBST(root->left, low, high) +
                rangeSumBST(root->right, low, high);
        }
        if(root->val<low){
           return rangeSumBST(root->right, low, high);
        }
        else{
           return rangeSumBST(root->left, low, high);
        }
    }
};