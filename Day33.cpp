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
};