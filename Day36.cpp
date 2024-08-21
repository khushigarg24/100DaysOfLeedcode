//202. Happy Number
class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        while(n!=1 && !s.contains(n)){
            s.insert(n);
            int sum=0;
            while(n>0){
                sum+=pow((n%10),2);
                n/=10;
            }
            n=sum;
        }
        return n==1;
    }
};


//199. Binary Tree Right Side View
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return {};
        map<int, int> mpp;
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        while (!q.empty()) {
            auto frontnode = q.front();
            q.pop();
            TreeNode* myNode = frontnode.second;
            int level = frontnode.first;

            if (mpp.find(level) == mpp.end())
                mpp[level] = myNode->val;

            if (myNode->right)
                q.push({level + 1, myNode->right});
            if (myNode->left)
                q.push({level + 1, myNode->left});
        }
        vector<int> ans;
        for (auto i : mpp) {
            ans.push_back(i.second);
        }
        return ans;
    }
};