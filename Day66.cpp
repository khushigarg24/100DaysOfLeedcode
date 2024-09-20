//5. Longest Palindromic Substring
class Solution {
    int max=0,start=0,end=0;
    public boolean isPalindrome(String s,int i,int j){
        while(i<j){
            char ch1=s.charAt(i);
            char ch2=s.charAt(j);
            if(ch1!=ch2){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    public String longestPalindrome(String s) {
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                if(isPalindrome(s,i,j)==true){
                    if((j-i+1)>max){
                        max=j-i+1;
                        start=i;
                        end=j;
                    }
                }
            }
        }
        return s.substring(start,end+1);
    }
}


// 8. String to Integer (atoi)
class Solution {
    public int myAtoi(String s) {
        s = s.trim();  // Remove leading/trailing spaces
        
        if (s.length() == 0) return 0;
        
        boolean neg = false;  // To track if the number is negative
        long ans = 0;         // To store the result
        
        int i = 0;
        char firstChar = s.charAt(0);
        
        // Handle the sign if present
        if (firstChar == '-') {
            neg = true;
            i++;
        } else if (firstChar == '+') {
            i++;
        }
        
        // Process the number part
        while (i < s.length()) {
            char ch = s.charAt(i);
            // '0'=48
            if (ch < '0' || ch > '9') break;  // Stop if non-digit character is found
            
            int dig = ch - '0';               // Convert char to number
            ans = ans * 10 + dig;
            
            // Check overflow
            if (!neg && ans > Integer.MAX_VALUE) return Integer.MAX_VALUE;
            if (neg && -ans < Integer.MIN_VALUE) return Integer.MIN_VALUE;
            
            i++;
        }
        if (neg) {return (int) -ans;} 
        else {return (int) ans;}
    }
}