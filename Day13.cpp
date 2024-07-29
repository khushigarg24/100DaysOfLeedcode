// 13. Roman to Integer
import java.util.HashMap;

class Solution {
    public int romanToInt(String s) {
        HashMap<Character, Integer> romanValues = new HashMap<>();
        romanValues.put('I', 1);
        romanValues.put('V', 5);
        romanValues.put('X', 10);
        romanValues.put('L', 50);
        romanValues.put('C', 100);
        romanValues.put('D', 500);
        romanValues.put('M', 1000);

        int result = romanValues.get(s.charAt(s.length()- 1)); 

        for (int i = s.length() - 2; i >= 0; i--) {
            if (romanValues.get(s.charAt(i)) < romanValues.get(s.charAt(i + 1))) {
                result -= romanValues.get(s.charAt(i));
            } else {
                result += romanValues.get(s.charAt(i));
            }
        }
        return result;   

    }
}


//3. Longest Substring Without Repeating Characters
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] dict = new int[256]; // Assuming ASCII characters
        Arrays.fill(dict, -1);
        int start = -1;
        int maxLength = 0;

        for (int i = 0; i < s.length(); i++) {
            int index = s.charAt(i);
            if (dict[index] > start) {
                start = dict[index];
            }
            dict[index] = i;
            maxLength = Math.max(maxLength, i - start);
        }

        return maxLength;
    }
}