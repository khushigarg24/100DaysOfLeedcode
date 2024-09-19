//9. Palindrome Number
class Solution {
public:
    bool isPalindrome(int x) {
        int ans=0;
        if(x<0){
            return false;
        }
        if(x>=0 && x<=9){
            return true;
        }
        int temp=x;
        while(x!=0){
            int num=x%10;
            if(ans>(INT_MAX-num)/10){
                return false;
            }
            ans=ans*10+num;
            x=x/10;
        }
        return ans==temp;
    }
};

//12. Integer to Roman
class Solution {
    public String intToRoman(int num) {
        String roman="";
        int[] values={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        String[] romanLetters={"M","CM","D","CD","C","XC","L","XL","X","IX","V",
        "IV","I"};
        for(int i=0;i<values.length;i++){
            while(num>=values[i]){
                roman=roman+romanLetters[i];
                num=num-values[i];
            }
        }
        return roman;
    }
}