//205. Isomorphic Strings
class Solution {
    public boolean isIsomorphic(String s, String t) {
        if(s.length()!=t.length()){
            return false;
        }

        Map<Character,Character> cm=new HashMap<>();

        for(int i=0;i<s.length();i++){
            char orig=s.charAt(i);
            char rep=t.charAt(i);

            if(!cm.containsKey(orig)){
                if(!cm.containsValue(rep)){
                    cm.put(orig,rep);
                }
                else{
                    return false;
                }
            }
            else{
                char mc=cm.get(orig);
                if(mc!=rep){
                    return false;
                }
            }
        }
        return true;
    }
}

//229. Majority Element II
import java.util.*;
class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int count;
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            count = 0;
            for (int j = 0; j < nums.length; j++) {
                if (nums[i] == nums[j]) {
                    count++;
                }
            }
            if (count > nums.length / 3 && !result.contains(nums[i])) {
                result.add(nums[i]);
            }
        }
        return result;
    }
}