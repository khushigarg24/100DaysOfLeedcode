//69. Sqrt(x)
class Solution {
    public int mySqrt(int x) {
        long start=1;
        long end=x;
        long ans=0;
        while(start<=end){
            long mid=start+(end-start)/2;
            if(mid*mid==x){
                ans=(int) mid;
                break;
            }
            else if(mid*mid<x){
                start=mid+1;
                ans=mid;
            }
            else{
                end=mid-1;
            }
        }
        return (int) ans;
    }
}

//367. Valid Perfect Square
class Solution {
    public boolean isPerfectSquare(int num) {
        if(num==1)return true;
        int start=1;
        int end=num/2;
        while(start<=end){
            int mid=(start+end)/2;
            long sq=(long)mid*mid;
            if(sq==num){
                return true;
            }
            else if(sq>num){
                end=mid-1;
            }
            else{
               start=mid+1; 
            }
        }
        return false;
    }
}