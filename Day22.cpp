// 94. Binary Tree Inorder Traversal
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans) {
        if(root!=NULL){
            inorder(root->left,ans);
            ans.push_back(root->val);
            inorder(root->right,ans);
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};

// 88. Merge Sorted Array
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last=m+n-1;
        while(m>0 && n>0){
            if(nums1[m-1]>nums2[n-1]){
                nums1[last]=nums1[m-1];
                m--;
            }
            else{
                nums1[last]=nums2[n-1];
                n--;
            }
            last--;
        }
        while(n>0){
            nums1[last]=nums2[n-1];
                n--;
                last--;
            } 
        } };