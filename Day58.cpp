//974. Subarray Sums Divisible by K
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
       unordered_map<int,int>m;
        int sum=0;
        int ans=0;
        int rem=0;
        m[rem]++;
        for(int i=0; i<nums.size();i++){
       sum+=nums[i];
       rem=sum%k;
            if(rem<0){                                                                
                rem+=k;
            }
            if(m.find(rem)!=m.end()){
                ans+=m[rem];
            }
            m[rem]++;
        }
        return ans;
    }
};


//977. Squares of a Sorted Array
class Solution {
    public int[] sortedSquares(int[] nums) {
        int n=nums.length;
        int left=0;
        int right=n-1;
        int ans[]=new int[n];
        int k=n-1;

        while(left<=right){
            if(Math.abs(nums[left])>Math.abs(nums[right])){
                ans[k--]=nums[left]*nums[left];
                left++;
            }
            else{
                ans[k--]=nums[right]*nums[right];
                right--;
            }
        }
        return ans;
    }
}