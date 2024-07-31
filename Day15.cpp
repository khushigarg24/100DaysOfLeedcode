// 20. Valid Parentheses
class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto c:s){
            if(st.empty()){
                st.push(c);
            }
            else if((st.top()=='(' && c==')') ||
             (st.top()=='[' && c==']')||
            (st.top()=='{' && c=='}')){
                st.pop();
            }
            else{
                st.push(c);
            }
        }
        if(st.size()==0){
            return true;
        }
        return false;
    }
};

//22. Generate Parentheses
class Solution {
public:
void helper(vector<string>&v,int n,int oc,int cc,string s){
    if(oc==n && cc==n){
        v.push_back(s);
        return;
    }
    if(oc<n){
        helper(v,n,oc+1,cc,s+"(");
    }
    if(cc<oc){
        helper(v,n,oc,cc+1,s+")");
    }
}
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        int oc=0;
        int cc=0;
        helper(v,n,oc,cc,"");
        return v;
    }
};