//1752. Check if Array Is Sorted and Rotated
class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(nums[i]>nums[(i+1)%n]){
                count++;
            }
        }
        return (count<=1);
    }
};


//1901. Find a Peak Element II
class Solution {
    public int[] findPeakGrid(int[][] mat) {
        int i=0;int j=0;
        while(i<mat.length && j<mat[0].length){
            if(i-1>=0 && mat[i-1][j]>mat[i][j]){
                i=i-1;
            }
            else if(j-1>=0 && mat[i][j-1]>mat[i][j]){
                j=j-1;
            }
            else if(i+1<mat.length && mat[i+1][j]>mat[i][j] ){
                i=i+1;
            }
            else if(j+1<mat[0].length && mat[i][j+1]>mat[i][j] ){
                j=j+1;
            }
            else{
                int[] ans={i,j};
                return ans;
            }
        }
        return new int[0];
    }
}