// 424. Longest Repeating Character Replacement
class Solution {
public:
    int characterReplacement(string s, int k) {
        int j=0;
        int ans=0,cnt[26]={};

        for(int i=0;i<s.size();i++){
            cnt[s[i]-'A']++;

            while(i-j+1-*max_element(cnt,cnt+26)>k){
                cnt[s[j]-'A']--;
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
}; 


//404. Sum of Left Leaves
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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        if (root->left != NULL && root->left->left == NULL &&
            root->left->right == NULL) {
            return root->left->val + sumOfLeftLeaves(root->right);
        }
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};
// 3 ke liye 9+ 20 ki call fir 15 + karke 7 ki call fir if chalega nahi null
// null left right se and 9+15 ans aagya