//37. Sudoku Solver
class Solution {

    public boolean isSafe(char[][] board,int row,int col,int number){
        //row and col ke liye
        for(int i=0;i<board.length;i++){
            if(board[i][col]==(char)(number+'0')){
                return false;
            }
            if(board[row][i]==(char)(number+'0')){
                return false;
            }
        }

        int sr=(row/3)*3;
        int sc=(col/3)*3;

        for(int i=sr;i<sr+3;i++){
            for(int j=sc;j<sc+3;j++){
                if(board[i][j]==(char)(number+'0')){
                    return false;
                }
            }
        }
        return true;
    }

    public boolean helper(char[][] board,int row,int col){

        if(row==board.length){
            return true;
        }

        int nrow=0;
        int ncol=0;

        if(col!=board.length-1){
            nrow=row;
            ncol=col+1;
        }
        else{
            nrow=row+1;
            ncol=0;
        }

        if(board[row][col]!='.'){
            if(helper(board,nrow,ncol)){
                return true;
            }
        }else{
            for(int i=1;i<=9;i++){
                if(isSafe(board,row,col,i)){
                    board[row][col]=(char)(i+'0');
                    if(helper(board,nrow,ncol)){
                        return true;
                    }
                    else{
                        board[row][col]='.';
                    }
                }
            }
        }
        return false;
    }

    public void solveSudoku(char[][] board) {
        helper(board,0,0);
    }
}

//Median of two sorted arrays
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n=nums1.length;
        int m=nums2.length;
        int i=0,j=0,k=0;
        int arr[]=new int[m+n];
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                arr[k++]=nums1[i];
                i++;
            }
            else{
                arr[k++]=nums2[j];
                j++;
            }
        }
        // agr nums1 me abhi bhii koi element pada ha 
        while(i<n){
            arr[k++]=nums1[i];
            i++;
        }
        // agr nums2 me abhi bhii koi element pada ha 
        while(j<m){
            arr[k++]=nums2[j];
            j++;
        }
        // now check if arr size is odd then return middle 
        if((m+n)%2!=0){
            return arr[(m+n)/2];
        }
        else{
            int x=(m+n)/2;
            double l=arr[x];
            double r=arr[x-1];
            return (l+r)/2;
        }
    }
}