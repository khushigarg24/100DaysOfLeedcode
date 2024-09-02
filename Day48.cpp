//496. Next Greater Element I
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> umap;
        stack<int>st;
        int n=nums2.size();

        for(int i=n-1;i>=0;i--){
            int ele=nums2[i];
            while(!st.empty() && st.top()<=ele){
                st.pop();
            }
            int res = (st.empty()) ? -1 : st.top();
            umap.insert({ele, res});
            st.push(ele);
        }
        vector<int> ans;
        for(auto x: nums1){
            ans.push_back(umap[x]);
        }
        
        return ans;
    }
};


//525. Contiguous Array
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> map;
        int sum = 0;
        int max = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                sum += -1;
            } else {
                sum += 1;
            }

            if (sum == 0) {
                if (max < i + 1) {
                    max = i + 1;
                }
            } else if (map.find(sum) != map.end()) {
                if (max < i - map[sum]) {
                    max = i - map[sum];
                }
            } else {
                map[sum] = i;
            }
        }
        return max;
    }
};