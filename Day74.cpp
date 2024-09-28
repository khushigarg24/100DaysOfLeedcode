//240. Search a 2D Matrix II
class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
                if(matrix[i][j]==target){
                    return true;
                }
            }
        }
        return false;
    }
}


//338. Counting Bits
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>mem(n+1);
        mem[0]=0;

        for(int i=1;i<=n;i++){
            mem[i]=mem[i/2] + i%2;
        }
        return mem;
    }
};