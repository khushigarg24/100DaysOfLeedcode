//128. Longest Consecutive Sequence
#include<unordered_set>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
int ans=0;
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i]-1)!=s.end()){
                continue;
            }
            else{
                int count=0;
                int current=nums[i];
                while(s.find(current)!=s.end()){
                    current++;
                    count++;
                }
                ans=max(ans,count);
            }
        }
return ans;
    }
};


//216. Combination Sum III
class Solution {
    List<List<Integer>>result=new ArrayList();
    void try_combination(List<Integer>combination,int k,int n,int start){
        if(k==combination.size()){
            if(n==0){
                result.add(new ArrayList<Integer>(combination));
                
            }
            return;
        }

        for(int i=start;i<=9;i++){
            combination.add(i);
            try_combination(combination,k,n-i,i+1);
            combination.remove(combination.size()-1);
        }
    }

    public List<List<Integer>> combinationSum3(int k, int n) {
        List<Integer> combination=new ArrayList();
        try_combination(combination,k,n,1);
        return result;
    }
}