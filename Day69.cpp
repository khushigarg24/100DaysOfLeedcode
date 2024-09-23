//38. Count and Say
class Solution {
public:
    string countAndSay(int n) {
        if(n==1)return "1";
        if(n==2)return "11";
        string s="11";
        for(int i=3;i<=n;i++){
            string t="";
            s=s+'&';
            int c=1;
            for(int j=1;j<s.length();j++){
                if(s[j]!=s[j-1]){
                    t=t+to_string(c);
                    t=t+s[j-1];
                    c=1;
                }
                else{
                    c++;
                }
               
            }
             s=t;
            
        }
        return s;
    }
};


//56. Merge Intervals
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedIntervals;
        if (intervals.size() == 0) {
            return mergedIntervals;
        }
        sort(intervals.begin(), intervals.end());

        vector<int> tempInterval = intervals[0];

        for (auto it : intervals) {
            if (it[0] <= tempInterval[1]) {
                tempInterval[1] = max(it[1], tempInterval[1]);
            } else {
                mergedIntervals.push_back(tempInterval);
                tempInterval = it;
            }
        }
        mergedIntervals.push_back(tempInterval);
        return mergedIntervals;
    }
};