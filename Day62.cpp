// 1539. Kth Missing Positive Number
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
         int missingCount = 0;
    int current = 1;
    int index = 0;
    int n = arr.size();
    
    while (missingCount < k) {
        if (index < n && arr[index] == current) {
            index++;
        } else {
            missingCount++;
            if (missingCount == k) {
                return current;
            }
        }
        current++;
    }
    return current;
    }
};


//1672. Richest Customer Wealth
class Solution {
    public int maximumWealth(int[][] accounts) {
        int ans=Integer.MIN_VALUE;
        for (int i = 0; i < accounts.length; i++) {
            int sum = 0;
            for (int j = 0; j < accounts[i].length; j++) {
                sum += accounts[i][j];
            }
            if(sum>ans){
                ans=sum;
            }
        }
        return ans;
    }
}