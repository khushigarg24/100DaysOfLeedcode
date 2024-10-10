//735. Asteroid Collision
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int &a:asteroids){

            while(!st.empty()&&a<0&&st.top()>0){
                int sum=a+st.top();

                if(sum<0){
                    st.pop();
                }
                else if(sum>0){
                    a=0;
                }
                else{
                    st.pop();
                    a=0;
                }
            }
            if(a!=0){
                st.push(a);
            }
        }

        int s=st.size();
        vector<int>result(s);

        int i=s-1;
        while(!st.empty()){
            result[i]=st.top();
            st.pop();
            i--;
        }
        return result;
    }
};


//739. Daily Temperatures
class Solution {
    public int[] dailyTemperatures(int[] t) {
        int res[]=new int[t.length];
        Stack<Integer> stack=new Stack<>();
        
        for(int i=0;i<t.length;i++){
            while(!stack.empty() && t[stack.peek()]<t[i]){
                Integer pop=stack.pop();
                res[pop]=i-pop;
            }
            stack.push(i);
        }
        return res;
    }
}