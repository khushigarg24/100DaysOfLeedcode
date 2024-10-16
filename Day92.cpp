//80. Remove Duplicates from Sorted Array II
class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums.length<3)return nums.length;
        int index=2;
        for(int i=2;i<nums.length;i++){
            if(nums[i]!=nums[index-2]){
                nums[index++]=nums[i];
            }
        }
        return index;
    }
}

//1318. Minimum Flips to Make a OR b Equal to c
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int total=0;
        for(int i=0;i<32;i++){
            if(c&(1<<i)){
                if(!(a&(1<<i) || b&(1<<i)))total++;
            }
            else{
                if(a&(1<<i))total++;
                if(b&(1<<i))total++;
            }
        }
        return total;
    }
};