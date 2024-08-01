// 26. Remove Duplicates from Sorted Array
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                nums[index]=nums[i];
                index++;
            }
        }
        return index;
    }
};

//28. Find the Index of the First Occurrence in a String
class Solution {
public:
    int strStr(string haystack, string needle) {
       int n=haystack.size(),m=needle.size();
       if(m==0){
        return 0;
       }
       if(n<m){
        return -1;
       }
       for(int i=0;i<n;i++){
        if(haystack[i]==needle[0]){
            if(haystack.substr(i,m)==needle){
                return i;
            }
        }
       }
       return -1;
    }
};