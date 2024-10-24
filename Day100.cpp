//224. Basic Calculator
class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int number = 0;
        int result = 0;
        int sign   = 1;
        
        for(int i = 0; i<s.length(); i++) {
            if(isdigit(s[i])) {
                number  = 10*number + (s[i] - '0');
            } else if(s[i] == '+') {
                result += sign*number;
                number  = 0;
                sign = 1; //For further
            } else if(s[i] == '-') {
                result += sign*number;
                number  = 0;
                sign = -1; //For further
            } else if(s[i] == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                number = 0;
                sign = 1;
            } else if(s[i] == ')') {
                result += sign*number;
                number = 0;
                int top = st.top(); st.pop();
                result *= top;
                top = st.top(); st.pop();
                result += top;
            }
        }
        result += (sign*number);
        return result;
    }
};


//1095. Find in Mountain Array
// This is MountainArray's API interface.
// You should not implement it, or speculate about its implementation
// interface MountainArray {
//     public int get(int index);
//     public int length();
// }

class Solution {
    public int findInMountainArray(int target, MountainArray mountainArr) {
        int peak = findPeakIndex(mountainArr);

        // Try to find the target in the ascending part
        int firstTry = binarySearch(mountainArr, target, 0, peak, true);
        if (firstTry != -1) {
            return firstTry;
        }

        // If not found, try to find it in the descending part
        return binarySearch(mountainArr, target, peak + 1, mountainArr.length() - 1, false);
    }

    private int findPeakIndex(MountainArray arr) {
        int start = 0;
        int end = arr.length() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;
            if (arr.get(mid) > arr.get(mid + 1)) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return start;
    }

    private int binarySearch(MountainArray arr, int target, int start, int end, boolean ascending) {
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int midValue = arr.get(mid);

            if (midValue == target) {
                return mid;
            }

            if (ascending) {
                if (target < midValue) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                if (target > midValue) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
        }
        return -1;
    }
}