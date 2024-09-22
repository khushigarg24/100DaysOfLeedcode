//34. Find First and Last Position of Element in Sorted Array
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans={-1,-1};
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                ans[0]=i;
                break;
            }
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]==target){
                ans[1]=i;
                break;
            }
        }
        return ans;
    }
};


//35. Search Insert Position
class Solution {
    public int searchInsert(int[] nums, int target) {
        int n=nums.length;
        for(int i=0;i<nums.length;i++){
            if(nums[i]>=target){
                return i;
            }
        }
        return n;
    }
}