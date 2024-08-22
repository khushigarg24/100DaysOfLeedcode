//217. Contains Duplicate
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>s(nums.begin(),nums.end());
        int x=nums.size();
        int y=s.size();
        if(x==y){
            return false;
        }
        else{
            return true;
        }
    }
};

//219. Contains Duplicate II
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i])){
                if((i-mp[nums[i]])<=k){
                    return true;
                }
            }
            mp[nums[i]]=i;
        }
        return false;
    }
};