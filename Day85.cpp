//649. Dota2 Senate
class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> dq,rq;

        for(int i=0;i<senate.size();i++){
            if(senate[i]=='R'){
                rq.push(i);
            }
            else{
                dq.push(i);
            }
        }

        while(!rq.empty() && !dq.empty()){
            int ri=rq.front();
            rq.pop();
            int di=dq.front();
            dq.pop();
            if(ri<di){
                rq.push(senate.size()+ri);
            }
            else{
                dq.push(senate.size()+di);
            }
        }
        return (rq.size()>dq.size())?"Radiant":"Dire";
    }
};


//700. Search in a Binary Search Tree

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root != NULL && root->val != val) {
            if (val < root->val) {
                root = root->left;
            } else {
                root = root->right;
            }
        }
        return root;
    }
};