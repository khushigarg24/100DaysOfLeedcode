//543. Diameter of Binary Tree
class Solution {
public:
int ans=0;
int height(TreeNode* root){
    if(root==NULL){
        return 0;
    }
    int lh=height(root->left);
    int rh=height(root->right);

    ans=max(ans,1+lh+rh);

    return 1+max(lh,rh);
}
    int diameterOfBinaryTree(TreeNode* root) {
        int data=height(root);
        return ans-1;
    }
};

//560. Subarray Sum Equals K

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, sum = 0;
        unordered_map<int, int> map{{0, 1}}; // Initialize map with sum 0 and count 1

        for (int num : nums) {
            sum += num;
            count += map[sum - k];
            map[sum]++;
        }

        return count;
    }
};