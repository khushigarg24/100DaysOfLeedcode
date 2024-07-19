// //1768 MERGE STRINGS ALTERNATIVELY
// class Solution {
// public:
//     string mergeAlternately(string word1, string word2) {
//         string finalstr="";
//         int i=0;
//         int j=0;

//         while(i<word1.size() && j<word2.size()){
//             finalstr.push_back(word1[i]);
//             i++;
//             finalstr.push_back(word2[j]);
//             j++;
//         }
//         while(i<word1.size()){
//             finalstr.push_back(word1[i]);
//             i++;
//         }
//         while(j<word2.size()){
//             finalstr.push_back(word2[j]);
//             j++;
//         }
//         return finalstr;
//     }
// };


// //1071 GREATEST COMMON DIVISOR OF STRINGS
// class Solution {
// public:
//     string gcdOfStrings(string str1, string str2) {
//         if((str1+str2)!=(str2+str1)){
//             return "";
//         }
//         int size1=str1.length();
//         int size2=str2.length();

//         string result=str1.substr(0,gcd(size1,size2));

//         return result;
//     }
// };