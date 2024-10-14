//2462. Total Cost to Hire K Workers
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();

        priority_queue<int, vector<int>, greater<int>> left, right;
        long long ans = 0;
        int count = 0, i = 0, j = n - 1;
        while (count < k) {
            while (left.size() < candidates && i <= j)
                left.push(costs[i++]);
            while (right.size() < candidates && j >= i)
                right.push(costs[j--]);

            int left_min, right_min;

            // Check if the left heap has elements
            if (left.size() > 0) {
                left_min = left.top();
            } else {
                left_min = INT_MAX; // If no elements, set left_min to INT_MAX
            }

            // Check if the right heap has elements
            if (right.size() > 0) {
                right_min = right.top();
            } else {
                right_min = INT_MAX; // If no elements, set right_min to INT_MAX
            }

            if (left_min <= right_min) {
                ans += left_min;
                left.pop();
            } else {
                ans += right_min;
                right.pop();
            }
            count++;
        }
        return ans;
    }
};


//2542. Maximum Subsequence Score
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>pairs;
        int n=nums1.size();
        for(int i=0;i<n;i++){
            pairs.push_back({nums2[i],nums1[i]});
        }

        sort(pairs.begin(),pairs.end());
        reverse(pairs.begin(),pairs.end());

        //to find min element
        priority_queue<int,vector<int>,greater<int>>pq;

        long long sum=0;
        long long ans=0;

        for(int i=0;i<n;i++){
            pq.push(pairs[i].second);
            sum+=pairs[i].second;

            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
            if(pq.size()==k)ans=max(ans,(long long)sum*pairs[i].first);
        }
        return ans;
    }
};