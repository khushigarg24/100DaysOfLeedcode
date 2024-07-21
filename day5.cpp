//STRING COMPRESSION
class Solution {
public:
    int compress(vector<char>& chars) {
        int size=chars.size();
        string s = "";
        chars.push_back('*');
        int count=1;
        for(int i=0;i<size;i++){
            char c=chars[i];
            if(chars[i+1]==c){
                count++;
            }
            else{
                s+=c;
                if(count>1){
                    s+=to_string(count);
                    count=1;
                }
            }
        }
        for(int i=0;i<s.size();i++){
            chars[i]=s[i];
        }
        return s.length();
    }
};