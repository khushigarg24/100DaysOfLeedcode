// 605. Can Place Flowers
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        if (n > size)
            return false;

        if (size == 1) return((n==1 && flowerbed[0]==0)||(n==0));

        int i = 0;
        while (i < size) {
            if (flowerbed[i] == 0) {
                if (i == 0) {
                    if (i + 1 < size && flowerbed[i + 1] == 0) {
                        flowerbed[i] = 1;
                        n--;
                    }
                } else if (i == size - 1) {
                    if (i - 1 >= 0 && flowerbed[i - 1] == 0) {
                        flowerbed[i] = 1;
                        n--;
                    }
                }
                else{
                    if(flowerbed[i+1]==0 && flowerbed[i-1]==0){
                        flowerbed[i]=1;
                        n--;
                    }
                }
            }
            i++;
        }
        if(n<=0){return true;}

        return false;
    }
};


//921. Minimum Add to Make Parentheses Valid
class Solution {
    public int minAddToMakeValid(String s) {
        int open=0,close=0;
       for(int i=0;i<s.length();i++){
         char ch=s.charAt(i);
        if(ch=='('){
            open++;
        }
        else{
            if(open<=0){
                close++;
                // closing loop
            }
            else{
                open--;
            }
        }
       }
        return open+close;
    }
}