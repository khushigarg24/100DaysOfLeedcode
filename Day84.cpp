//374. Guess Number Higher or Lower
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l=1;
        int r=n;

        while(l<=r){
            int guessno=l+(r-l)/2;
            int val=guess(guessno);

            if(val==0){
                return guessno;
            }
            else if(val==-1){
                r= guessno-1;
            }
            else{
                l=guessno+1;
            }

        }
        return -1;
    }
};

//383. Ransom Note
class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int[] count = new int[26];
        for (char ch : magazine.toCharArray()) {
            count[ch - 'a']++;
        }
        for (char ch : ransomNote.toCharArray()) {
            count[ch - 'a']--;
            if (count[ch - 'a'] < 0) {
                return false;
                // iska matlab hai ransom note ki occurence zyada hogayi - mei aagya but hume
                // toh magaziner dalne ke baad voh zero chhaiye thaa so we returned false
            }
        }
        return true;
    }
}