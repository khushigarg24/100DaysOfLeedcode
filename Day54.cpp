//704. Binary Search
class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int i=0; i<nums.size();i++){
            if(target==nums[i]){
                return i;
            }
        }
        return -1;
    }
};


//744. Find Smallest Letter Greater Than Target
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int start = 0;
        int end = letters.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (target <letters[mid])
            { end=mid-1; }
            else  {
                   start = mid + 1;
                }
        }
        return letters[start % letters.size()];
    }
};