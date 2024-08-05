//71. Simplify Path
class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        string res;
        for(int i=0;i<path.size();i++){
            if(path[i]=='/'){
                continue;
            }
            string temp;
            while(i<path.size() && path[i]!='/'){
                temp+=path[i];
                i++;
            }
            if(temp=="."){
                continue;
            }
            else if(temp==".."){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(temp);
            }
        }
        while(!st.empty()){
            res='/'+st.top()+res;
            st.pop();
        }
        if(res.size()==0){
            return "/";
        }
        return res;
    }
};

//67. Add Binary
class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length(), m = b.length();
        int i = n - 1, j = m - 1, carry = 0;
        string result = "";

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0)
                sum += a[i] - '0';
            if (j >= 0)
                sum += b[j] - '0';
            if (sum > 1) {
                carry = 1;
            } else {
                carry = 0;
            }

            result += to_string(sum % 2);
            i--;
            j--;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};