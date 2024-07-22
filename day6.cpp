//11 CONTAINER WITH MOST WATER
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0;
        int r=n-1;
        int ans=0;
        while(l<r){
            ans=max(ans,(r-l)*min(height[l],height[r]));
            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return ans;
    }
};

//392 IS SUBSEQUENCE
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length()==0){
            return true;
        }
        if(s.length()>t.length()){
            return false;
        }

        int j=0;
        for(int i=0;i<t.length();i++){
            if(s[j]==t[i]){
                j++;
            }
            if(j==s.length()){
                return true;
            }
        }
        return false;
    }
};