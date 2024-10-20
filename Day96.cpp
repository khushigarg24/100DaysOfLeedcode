//452. Minimum Number of Arrows to Burst Balloons
class Solution {
    public int findMinArrowShots(int[][] points) {
        // sort array on basis of y point
        if(points.length==0)return 0;
        Arrays.sort(points,(a,b)->Integer.compare(a[0],b[0]));
        int arrow=1;
        int end=points[0][1];
        for(int i=1;i<points.length;i++){
            if(points[i][0]>end){
                arrow++;
                end=points[i][1];
            }
            else{
                end=Math.min(end,points[i][1]);
            }
        }
        return arrow;
    }
}

//150. Evaluate Reverse Polish Notation
class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> st=new Stack<>();
        String operators="+-*/";
        for(String token:tokens){
            if(operators.indexOf(token)!=-1){
                int d2=st.pop();
                int d1=st.pop();
                int res=0;
                if(token.equals("+")){
                    res=d1+d2;
                }
                else if(token.equals("-")){
                    res=d1-d2;
                }
                else if(token.equals("*")){
                    res=d1*d2;
                }
                else if(token.equals("/")){
                    res=d1/d2;
                }
                st.push(res);
            }
            else{
                st.push(Integer.parseInt(token));
            }
        }
        return st.peek();
    }
}