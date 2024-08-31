//437. Path Sum III
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
void checkSum(TreeNode* root,int &count,int targetSum,vector<int>addthese){
    if(!root)return;

    addthese.push_back(root->val);
    checkSum(root->left,count,targetSum,addthese);
    checkSum(root->right,count,targetSum,addthese);

    long long sum=0;
for(int i=addthese.size()-1;i>=0;i--){
    sum=sum+addthese[i];
    if(sum==targetSum)count++;
}
    addthese.pop_back();
}
    int pathSum(TreeNode* root, int targetSum) {
        int count=0;
        vector<int>addthese;
        checkSum(root,count,targetSum,addthese);
        return count;
    }
};

//442. Find All Duplicates in an Array

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> countMap;
        vector<int> result;

        for (int i : nums) {
            countMap[i]++;
        }

        for (auto j : countMap) {
            if (j.second == 2) {
                result.push_back(j.first);
            }
        }

        return result;
    }
};