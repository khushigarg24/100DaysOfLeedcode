// 1903. Largest Odd Number in String
class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.length();

        for(int i=n-1;i>=0;i--){
            if((num[i]-'0')%2!=0){
                return num.substr(0,i+1);
            }
        }
        return "";
    }
};


//2149. Rearrange Array Elements by Sign
class Solution {
    public int[] rearrangeArray(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];
        int posi = 0;
        int neg = 1;

        for (int num : nums) {
            if (num > 0) {
                result[posi] = num;
                posi += 2;
            } else {
                result[neg] = num;
                neg += 2;
            }
        }
        return result;
    }
}