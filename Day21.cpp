//73. Set Matrix Zeroes
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> x, y;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        }
        // row->0
        for (int i = 0; i < x.size(); i++) {
            int index = x[i];
            for (int j = 0; j < n; j++) {
                matrix[index][j] = 0;
            }
        }

        // col->0
        for (int i = 0; i < y.size(); i++) {
            int index = y[i];
            for (int j = 0; j < m; j++) {
                matrix[j][index] = 0;
            }
        }
    }
};

//75. Sort Colors
class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(),nums.end());
    }
};