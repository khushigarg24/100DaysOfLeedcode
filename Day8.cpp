// 1456. Maximum Number of Vowels in a Substring of Given Length
class Solution {
public:
    int maxVowels(string s, int k) {
        int count = 0;
        string vowels = "aeiou";

        for (int i = 0; i < k; i++) {
            if (vowels.find(s[i]) != string::npos) {
                count++;
            }

        }
        int maxx=count;
        int j=0;

        for(int i=k;i<s.length();i++){
            if (vowels.find(s[i]) != string::npos) count++;
            if (vowels.find(s[j]) != string::npos) count--;
            j++;

            maxx=max(maxx,count);
            if(maxx==k)return maxx;
        }
        return maxx;
    }
};

//1004. Max Consecutive Ones III
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        while(j<nums.size()){
            if(nums[j]==0){
                k--;
            }
            if(k<0){
                if(nums[i]==0){
                    k++;
                }
                i++;
            }
            j++;
        }
        return j-i;
    }
};