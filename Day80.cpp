//17. Letter Combinations of a Phone Number
class Solution {
private:
    void solve(string digit, string output, int index, vector<string>& ans, string mapping[] ) {
        
        //base case
        if(index >= digit.length()) {
            ans.push_back(output);
            return;
        }
        
        int number = digit[index] - '0';
        string value = mapping[number];
        
        for(int i=0; i<value.length(); i++) {
            output.push_back(value[i]);
            solve(digit, output, index+1, ans, mapping);
            output.pop_back();
        }
        
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0)
            return ans;
        string output;
        int index = 0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl","mno","pqrs","tuv","wxyz"};
        solve(digits, output, index, ans, mapping);
        return ans;
    }
};


//1781. Sum of Beauty of All Substrings
class Solution {

    public int getmin(int freq[]){
        int min=Integer.MAX_VALUE;
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                  min=Math.min(min,freq[i]);
            }
          
        }
        return min;
    }

     public int getmax(int freq[]){
        int max=0;
        for(int i=0;i<26;i++){
            max=Math.max(max,freq[i]);
        }
        return max;
    }


    public int beautySum(String s) {
        int sum=0;
        for(int i=0;i<s.length();i++){
            int freq[]=new int[26];
            for(int j=i;j<s.length();j++){
                freq[s.charAt(j)-'a']++;
                int beauty=getmax(freq)-getmin(freq);
                sum+=beauty;
            }
        }
        return sum;
    }
}