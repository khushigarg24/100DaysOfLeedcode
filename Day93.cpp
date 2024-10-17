//6. Zigzag Conversion
class Solution {
    public String convert(String s, int numRows) {
        String ans[]=new String[numRows];
        for(int i=0;i<numRows;i++){
            ans[i]="";
        }
        int i=0;
        while(i<s.length()){
            for(int index=0;index<numRows && i<s.length();index++){
                ans[index]+=s.charAt(i++);
            }
            for(int index=numRows-2;index>0 && i<s.length();index--){
                ans[index]+=s.charAt(i++);
            }
        }
        String res="";
        for(String str:ans){
            res+=str;
        }
        return res;
    }
}


//209. Minimum Size Subarray Sum
class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int start=0,currsum=0,window=Integer.MAX_VALUE;
        for(int end=0;end<nums.length;end++){
            currsum+=nums[end];
            while(currsum>=target){
                window=Math.min(window,end-start+1);
                currsum-=nums[start];
                start++;
            }
        }
        if(window==Integer.MAX_VALUE){
            return 0;
        }
        return window;
    }
}