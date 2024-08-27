//268. Missing Number
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            ans^=(nums[i]^i);
        }
        ans^=n;
        return ans;
    }
}; 

//257. Binary Tree Paths
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
    void preorder(vector<string>& v, string s, TreeNode* root) {
        if(!root)return;
        s+=to_string(root->val);
        s+="->";

        if(!root->left && !root->right){
            s.pop_back();
            s.pop_back();
            v.push_back(s);
        }
        preorder(v, s, root->left);
        preorder(v, s, root->right);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        string s = "";
        preorder(v, s, root);
        return v;
    }
};