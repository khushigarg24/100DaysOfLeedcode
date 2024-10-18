//36. Valid Sudoku
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<string>s;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    string row="row"+to_string(i)+board[i][j];
                    string col="col"+to_string(j)+board[i][j];
                    string box="box"+to_string((i/3)*3+(j/3))+board[i][j];

                    if(s.find(row)==s.end() && s.find(col)==s.end() && s.find(box)==s.end()){
                        s.insert(row);
                        s.insert(col);
                        s.insert(box);
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

//290. Word Pattern
import java.util.HashMap;

class Solution {
    public boolean wordPattern(String pattern, String s) {
        String arr[] = s.split(" ");
        if (pattern.length() != arr.length) return false;
        HashMap<Character, String> hm = new HashMap<Character, String>();
        
        for (int i = 0; i < pattern.length(); i++) {
            char ch = pattern.charAt(i);
            if (hm.containsKey(ch)) {
                if (!hm.get(ch).equals(arr[i])) {
                    return false;
                }
            } else {
                if (hm.containsValue(arr[i])) {
                    return false;
                }
                hm.put(ch, arr[i]);
            }
        }
        return true;
    }
}