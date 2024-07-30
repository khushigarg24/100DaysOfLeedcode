//7. Reverse Integer
class Solution {
public:
    int reverse(int x) {
        int ans=0;
        while(x!=0){
            int digit=x%10;
            if((ans>INT_MAX/10) || (ans<INT_MIN/10)){
                return 0;
            }
            ans=(ans*10) +digit;
            x=x/10;
        }
        return ans;
    }
};

//14. Longest Common Prefix
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }
        sort(strs.begin(),strs.end());
        string str1=strs[0];
        string str2=strs[strs.size()-1];
        int index=0;
        while(index<str1.length()){
            if(str1[index]==str2[index]){
                index++;
            }
            else{
                break;
            }
        }
        return str1.substr(0,index);
    }
};