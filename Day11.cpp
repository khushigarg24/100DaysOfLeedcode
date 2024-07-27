// 1207. Unique Number of Occurrences
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int i = 0; i < arr.size(); i++) {
            freq[arr[i]]++;
        }
        unordered_set<int> check;
        for (auto i : freq) {
            check.insert(i.second);
        }
        return (freq.size() == check.size());
    }
};

// 1657. Determine if Two Strings Are Close
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.length() != word2.length()) {
            return false;
        }

        unordered_map<char, int> map1, map2;

        for (int i = 0; i < word1.length(); i++) {
            map1[word1[i]]++;
        }

        for (int i = 0; i < word2.length(); i++) {
            map2[word2[i]]++;
        }

        for (int i = 0; i < word1.length(); i++) {
            if (map2.find(word1[i]) == map2.end()) {
                return false;
            }
        }
        for (int i = 0; i < word2.length(); i++) {
            if (map1.find(word2[i]) == map1.end()) {
                return false;
            }
        }
        vector<int>vect1,vect2;
        for(auto i:map1){
            vect1.push_back(i.second);
        }
        for(auto i:map2){
            vect2.push_back(i.second);
        }
        sort(vect1.begin(),vect1.end());
        sort(vect2.begin(),vect2.end());

        return vect1==vect2;
    }
};