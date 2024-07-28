//2352. Equal Row and Column Pairs
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> freq;
        int n = grid.size();
        int count = 0;

        for (auto i : grid) {
            freq[i]++;
        }

        for (int j = 0; j < n; j++) {
            vector<int> helper;
            for (int i = 0; i < n; i++) {
                helper.push_back(grid[i][j]);
            }
            count+=freq[helper];
        }
        return count;
    }
};

//2390. Removing Stars From a String
class Solution {
public:
    string removeStars(string s) {
        stack<char>st;

        for(int i=0;i<s.length();i++){
            if(s[i]=='*'){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(s[i]);
            }
        }

        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};