//53. Maximum Subarray
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr=nums[0];
        int max2=nums[0];

        for(int i=1;i<nums.size();i++){
            if(curr+nums[i]>nums[i]){
                curr+=nums[i];
            }
            else{
                curr=nums[i];
            }
            max2=max(max2,curr);
        }
        return max2;

    }
};

//49. Group Anagrams
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>>umap;
        for(auto x:strs){
            string temp=x;
            sort(x.begin(),x.end());
            umap[x].push_back(temp);
        }
        for(auto x:umap){
            ans.push_back(x.second);
        }
        return ans;
    }
};