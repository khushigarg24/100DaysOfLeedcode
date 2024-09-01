//453. Minimum Moves to Equal Array Elements
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min1 = INT_MAX;
        int res = 0;
        for (int num : nums) {
            min1 = min(num, min1);
        }
        for (int num : nums) {
            res += num-min1;
        }
        return res;
    }
};


//485. Max Consecutive Ones
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int maxCount = 0;
        int count = 0;

        for (int num : nums) {
            if (num == 1) {
                count++;
                maxCount = Math.max(maxCount, count);
            } else {
                count = 0;
            }
        }

        return maxCount;
    }
}