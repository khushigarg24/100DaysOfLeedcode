//1021. Remove Outermost Parentheses
class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0;
        string ans="";
        bool flag =true;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                count++;
            }
            else if(s[i]==')'){
                count--;
            }
            if(count==1 && flag==true){
                flag=false;
                continue;
            }
            if(count==0 && flag==false){
                flag=true;
                continue;
            }
            ans+=s[i];
        }
        return ans;
    }
};


//205. Isomorphic Strings
class Solution {
    public boolean isIsomorphic(String s, String t) {
        if(s.length()!=t.length()){
            return false;
        }

        Map<Character,Character> cm=new HashMap<>();

        for(int i=0;i<s.length();i++){
            char orig=s.charAt(i);
            char rep=t.charAt(i);

            if(!cm.containsKey(orig)){
                if(!cm.containsValue(rep)){
                    cm.put(orig,rep);
                }
                else{
                    return false;
                }
            }
            else{
                char mc=cm.get(orig);
                if(mc!=rep){
                    return false;
                }
            }
        }
        return true;
    }
}