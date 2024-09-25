//118. Pascal's Triangle
class Solution {
    public List<List<Integer>> generate(int n) {
        int[][] p=new int[n][];

        for(int i=0;i<n;i++){
            p[i]=new int[i+1];

            p[i][0]=p[i][i]=1;

            for(int j=1;j<i;j++){
                p[i][j]=p[i-1][j-1]+p[i-1][j];
            }

        }

        List<List<Integer>> result=new ArrayList<>();
        for(int i=0;i<n;i++){
            List<Integer> row=new ArrayList<>();
           for(int j=0;j<p[i].length;j++){
                row.add(p[i][j]);
           }
           result.add(row);
        }
        return result;
    }
}

//125. Valid Palindrome
class Solution {
    public boolean isPalindrome(String s) {
        int p1=0;
        int p2=s.length()-1;
        s=s.toLowerCase();

        while(p1<p2){
            char ch1=s.charAt(p1);
            char ch2=s.charAt(p2);
            if(!(ch1>='a' && ch1<='z'|| ch1>='0' && ch1<='9')){
                p1++;
                continue;
            }
            if(!(ch2>='a' && ch2<='z'|| ch2>='0' && ch2<='9')){
                p2--;
                continue;
            }
            if(ch1!=ch2){
                return false;
            }
            p1++;
            p2--;
        }
        return true;
    }
}