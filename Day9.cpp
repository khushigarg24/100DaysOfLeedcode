// 1493. Longest Subarray of 1's After Deleting One Element
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mid = -1;
        int i = 0;
        int j = 0;
        int ans = 0;

        while (j < nums.size()) {
            if (nums[j] == 0) {
                ans = max(ans, j - i - 1);
                i = mid + 1;
                mid = j;
            }
            j++;
        }
        ans = max(ans, j - i - 1);
        return ans;
    }
};

//1732. Find the Highest Altitude
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxx=0;
        int sum=0;

        for(int i=0;i<gain.size();i++){
            sum=sum+gain[i];
            maxx=max(maxx,sum);
        }
        return maxx;
    }
};