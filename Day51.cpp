//561. Array Partition
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;

        for(int i=0;i<nums.size()-1;i+=2){
            ans+=min(nums[i],nums[i+1]);
        }
        return ans;
    }
};


//572. Subtree of Another Tree

class Solution {
public:   
string preOrderTraversal(TreeNode* node) {
        if (node == nullptr) {
            return "null";
        }

stringstream ss;
        ss << "^" << node->val;
        ss << preOrderTraversal(node->left);
        ss << preOrderTraversal(node->right);
        return ss.str();
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string fullTree = preOrderTraversal(root);
        string subTree = preOrderTraversal(subRoot);
        return fullTree.find(subTree) !=string::npos;
    }
}