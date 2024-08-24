//227. Basic Calculator II
class Solution {
    public int calculate(String s) {
        if(s==null || s.length()==0)return 0;
        Stack<Integer>st=new Stack<>();
        int curr=0;
        char op='+';
        // convert string into char array
        char[] ch= s.toCharArray();
        for(int i=0;i<ch.length;i++){
            // if char is digit
            // this is char array but curr is int so for convertion we do this
            if(Character.isDigit(ch[i])){
                curr=curr*10+ch[i]-'0';
            }
            if(!Character.isDigit(ch[i]) && ch[i]!=' ' || i==ch.length-1){
                if(op=='+'){
                    st.push(curr);
                }
                else if(op=='-'){
                     st.push(-curr);
                }
                else if(op=='*'){
                     st.push(st.pop()*curr);
                }
                else if(op=='/'){
                    st.push(st.pop()/curr);
                }
                op=ch[i];
                curr=0;
            }
        }
        int sum=0;
        while(!st.empty()){
            sum+=st.pop();
        }
        return sum;
    }
}


//230. Kth Smallest Element in a BST
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
private:
int res;
 void inorder(TreeNode* root, int &k){
    if(!root)return;
    inorder(root->left,k);
    if(--k==0)res=root->val;
    inorder(root->right,k);
 }


public:
    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        return res;
    }
};