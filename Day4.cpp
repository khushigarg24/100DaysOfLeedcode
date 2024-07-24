//238. Product of Array Except Self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,1);
        int prefix=1;
        int postfix=1;

        for(int i=0;i<n;i++){
            ans[i]=prefix;
            prefix*=nums[i];
        }

         for(int i=n-1;i>=0;i--){
            ans[i]*=postfix;
            postfix*=nums[i];
        }
        return ans;
    }
};



//334. Increasing Triplet Subsequence
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        if(n<3){
            return false;
        }
        int middle=INT_MAX;
        int smallest=INT_MAX;

        for(int i=0;i<n;i++){
            if(nums[i]>middle){
                return true;
            }
            else if(nums[i]>smallest && nums[i]<middle){
                middle=nums[i];
            }
            else if(nums[i]<smallest){
                smallest=nums[i];
            }
        }
        return false;
    }
};
