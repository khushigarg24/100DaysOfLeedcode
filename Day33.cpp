//167. Two Sum II - Input Array Is Sorted
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0;
        int j=numbers.size()-1;

        while(i<j){
            if(numbers[i]+numbers[j]==target){
                return {i+1,j+1};
            }
            else if(numbers[i]+numbers[j]<target){
                i++;
            }
            else{
                j--;
            }
        }
        return {};
    }
};

//162. Find Peak Element
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
    int start=0;
    int end=nums.size()-1;

    while(start<end){
        int mid=start+(end-start)/2;
        if(nums[mid]>nums[mid+1]){
            end=mid;
        }
        else{
            start=mid+1;
        }
    }
    return start;
    }
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