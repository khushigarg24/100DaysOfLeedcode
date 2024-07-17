// 3Sum
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int j=i+1;
            int k=n-1;

            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0){
                    j++;
                }
                else if(sum>0){
                    k--;
                }
                else{
                    vector<int>temp={nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;

                    while(j<k && nums[j]==nums[j-1]){
                        j++;
                    }
                    while(j<k && nums[k]==nums[k+1]){
                        k--;
                    }
                }
            }
        }
        return ans;
    }
};

// two Sum
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>ans;
        int n=nums.size();

        for(int i=0;i<n;i++){
            int num=nums[i];
            int more=target-num;

            if(ans.find(more)!=ans.end()){
                return{ans[more],i};
            }
            ans[num]=i;
        }
        return{-1,-1};
        
    }
};