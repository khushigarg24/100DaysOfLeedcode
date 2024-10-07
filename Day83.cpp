//224. Basic Calculator
class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int number = 0;
        int result = 0;
        int sign   = 1;
        
        for(int i = 0; i<s.length(); i++) {
            if(isdigit(s[i])) {
                number  = 10*number + (s[i] - '0');
            } else if(s[i] == '+') {
                result += sign*number;
                number  = 0;
                sign = 1; //For further
            } else if(s[i] == '-') {
                result += sign*number;
                number  = 0;
                sign = -1; //For further
            } else if(s[i] == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                number = 0;
                sign = 1;
            } else if(s[i] == ')') {
                result += sign*number;
                number = 0;
                int top = st.top(); st.pop();
                result *= top;
                top = st.top(); st.pop();
                result += top;
            }
        }
        result += (sign*number);
        return result;
    }
};


//289. Game of Life
class Solution {
    public void gameOfLife(int[][] board) {
        // firstwe make a clone to store initially the board
        int clone[][] = new int[board.length][board[0].length];
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                clone[i][j] = board[i][j];
            }
        }
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if(clone[i][j]==1){
                    //now check live neighbours
                    int live=findLive(i,j,clone);
                    if(live==2 || live==3){
                        board[i][j]=1;
                    }
                    else{
                        board[i][j]=0;
                    }
                }
                else{
                    if(findLive(i,j,clone)==3){
                        board[i][j]=1;
                    }
                    else{
                        board[i][j]=0;
                    }
                }
            }
        }
    }

    private int findLive(int i,int j,int[][] board){
        int live=0;
        if(i+1<board.length && board[i+1][j]==1)live++;
        if(j+1<board[0].length && board[i][j+1]==1)live++;
        if(i-1>=0 && board[i-1][j]==1)live++;
        if(j-1>=0 && board[i][j-1]==1)live++;

        if(i+1<board.length &&j+1<board[0].length && board[i+1][j+1]==1)live++;
        if(i+1<board.length && j-1>=0 && board[i+1][j-1]==1)live++;
        if(i-1>=0 && j+1<board[0].length && board[i-1][j+1]==1)live++;
        if(i-1>=0 && j-1>=0 && board[i-1][j-1]==1)live++;
        return live;
    }
}