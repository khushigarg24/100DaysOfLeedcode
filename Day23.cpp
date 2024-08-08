//95. Unique Binary Search Trees II
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
    vector<TreeNode*> generateTrees(int n) {
        return helper(1,n);
        }
        vector<TreeNode*>helper(int s,int e){
            vector<TreeNode*>v;
            if(s>e){
                v.push_back(NULL);
                return v;
            }
            if(s==e){
                v.push_back(new TreeNode(s));
                return v;
            }
            for(int i=s;i<=e;i++){
                auto left=helper(s,i-1);
                auto right=helper(i+1,e);
                for(auto& l:left){
                    for(auto& r:right){
                        TreeNode* root=new TreeNode(i);
                        root->left=l;
                        root->right=r;
                        v.push_back(root);
                    }
                }
            }
        return v;
    }
};


//100 Same Tree
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL || q == NULL)
            return p == q;
        if (p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};