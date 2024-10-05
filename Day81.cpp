//27. Remove Element
class Solution {
    public int removeElement(int[] nums, int val) {
       int count =0;
       for(int i=0;i<nums.length;i++){
        if(nums[i]!=val){
            nums[count]=nums[i];
            count++;
        }
       }
       return count;
    }
}

//58. Length of Last Word
class Solution {
    public int lengthOfLastWord(String s) {
        String str=s.trim();
       int count=0;
       for(int i=str.length()-1;i>=0;i--){
        if(str.charAt(i)!=' '){
            count++;
        }
        else{
            break;
        }
       }
       return count;
    }
}