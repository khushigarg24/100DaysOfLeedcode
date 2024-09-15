//1448. Count Good Nodes in Binary Tree
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
    void checknodes(TreeNode* root, int &count, int &currmax) {
        if (!root) return;
        if (root->val >= currmax) {
            count++;
            currmax = root->val;
        }
        int left_max = currmax;
        int right_max = currmax;
        checknodes(root->left, count, left_max);
        checknodes(root->right, count, right_max);
    }

    int goodNodes(TreeNode* root) {
        int count = 0;
        int currmax = INT_MIN;
        checknodes(root, count, currmax);
        return count;
    }
};


//1492. The kth Factor of n
class Solution {
    public int kthFactor(int n, int k) {
        int count=0;
        for(int i=1;i<=n;i++){
            if(n%i==0){
                count++;
            }
            if(count==k){
                return i;
            }
        }
        return -1;
    }
}