//168. Excel Sheet Column Title
class Solution {
public:
    string convertToTitle(int col) {
        string result;
        while (col > 0) {
            int r = (col - 1) % 26;
            result += (char)(r + 'A');
            col = (col - 1) / 26;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

//169. Majority Element
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count =1;
        int res=nums[0];
        for(int i=1;i<nums.size();i++){
            if(count==0){
                res=nums[i];
            }
            if(res==nums[i]){
                count ++;
            }
            else{
                count --;
            }
        }
        return res;
    }
};