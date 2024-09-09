// 852. Peak Index in a Mountain Array
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start=0;
    int end=arr.size()-1;

    while(start<end){
        int mid=start+(end-start)/2;
        if(arr[mid]>arr[mid+1]){
            end=mid;
        }
        else{
            start=mid+1;
        }
    }
    return start;
    }
};


//872. Leaf-Similar Trees
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

void checkLeaf(TreeNode* root,vector<int>&data){
    if(!root->left && ! root->right){
        data.push_back(root->val);
        return ;
    }
    if(root->left){
        checkLeaf(root->left,data);
    }
    if(root->right){
        checkLeaf(root->right,data);
    }

}

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> data1;
        vector<int>data2;

        checkLeaf(root1,data1);
        checkLeaf(root2,data2);

        if(data1.size()!=data2.size()){
            return false;
        }
        int i=0;
        while(i<data1.size()){
            if(data1[i]!=data2[i]){
                return false;
            }
            i++;
        }
        return true;
    }
};