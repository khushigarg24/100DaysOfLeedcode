// REVERSE WORDS IN A STRING
class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        string helper = "";

        for (int i = s.length()-1; i >= 0; i--) {
            if (s[i] == ' ') {
                if (helper.size() > 0) {
                    reverse(helper.begin(), helper.end());
                    ans += helper;
                    ans += " ";
                    helper = "";
                }
            } 
            else {
                helper += s[i];
            }
        }
        if (helper.size() > 0) {
            reverse(helper.begin(), helper.end());
            ans += helper;
        } else if (ans.size() > 0) {
            ans.pop_back();
        }
        return ans;
    }
};

//REVERSE VOWELS OF A STRING
class Solution {
public:
    string reverseVowels(string s) {
        if(s.length()<2){
            return s;
        }

        int i=0;
        int j=s.length()-1;
        string vowels="aeiouAEIOU";

        while(i<j){
            while(i<j && (vowels.find(s[i])==string::npos)){
                i++;
            }
             while(j>i && (vowels.find(s[j])==string::npos)){
                j--;
            }
            if(i<j){
                swap(s[i],s[j]);
            }
            i++;
            j--;
        }
        return s;
    }
};