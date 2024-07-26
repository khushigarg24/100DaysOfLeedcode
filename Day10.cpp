// 724. Find Pivot Index
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0,sum1=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
        }
        for(int i=0;i<nums.size();i++){
            sum=sum-nums[i];
            if(sum==sum1){
                return i;
            }
            sum1=sum1+nums[i];
        }
        return -1;
    }
};

// 2215. Find the Difference of Two Arrays
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> setFirst(nums1.begin(),nums1.end());
        unordered_set<int> setTwo(nums2.begin(),nums2.end());
        vector<vector<int>>ans(2);

        for(int num:setFirst){
            if(setTwo.count(num)==0){
                ans[0].push_back(num);
            }
        }
        for(int num:setTwo){
            if(setFirst.count(num)==0){
                ans[1].push_back(num);
            }
        }
        return ans;
    }
};