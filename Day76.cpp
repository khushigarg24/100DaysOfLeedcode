//41. First Missing Positive
class Solution {
    public int firstMissingPositive(int[] arr) {
        int i = 0;
        while (i < arr.length) {
            int correct = arr[i] - 1;
            if (arr[i] > 0 && arr[i] <= arr.length && arr[i] != arr[correct]) {
                swap(arr, i, correct);
            } else {
                i++;
            }
        }
        for (int index = 0; index < arr.length; index++) {
            if (arr[index] != index + 1) {
                return index + 1;
            }
        }
        return arr.length+1;
    }

    static void swap(int[] arr, int first, int second) {
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }
}


//242. Valid Anagram
class Solution {
    public boolean isAnagram(String s, String t) {
        int m=s.length();
        int n=t.length();
        if(m!=n){
            return false;
        }
int count[]=new int[26];
        for(int i=0;i<m;i++){
            count[s.charAt(i)-'a']++;
        }

        for(int i=0;i<n;i++){
            count[t.charAt(i)-'a']--;
        }


        for(int i=0;i<26;i++){
            if(count[i]!=0){
                return false;
            }
        }
        return true;
    }
}