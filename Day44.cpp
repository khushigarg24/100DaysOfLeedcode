// 371. Sum of Two Integers
class Solution {
public:
    int getSum(int a, int b) {
        if(b==0){
            return a;
        }
        int sum=a^b;
        int cr=(unsigned int)(a&b)<<1;
        return getSum(sum,cr);
    }
};

//394. Decode String
class Solution {
public:
    string decodeString(string s) {
        stack<pair<int, string>> helper;
        string ans;
        int i = 0;

        while (i < s.length()) {
            // suppose we get a no here
            if (s[i] >= '0' && s[i] <= '9') {
                // agar multiple no hue usko handle krlo aur i mo store krake
                // rkhlo
                int j = i;

                while (s[i] >= '0' && s[i] <= '9') {
                    i++;
                }
                int num = stoi(s.substr(j, i - j));
                // j: This is the starting index of the
                // substring within the original string.
                // Think of it as the position of the first character you want
                // to include. i-j: This specifies the length of the substring.
                helper.push({num,""});
            }

            else if (s[i] >= 'a' && s[i] <= 'z') {
                int j = i;

                while (s[i] >= 'a' && s[i] <= 'z') {
                    i++;
                }
                string curr = s.substr(j, i - j);

                // agar empty hai toh ans ka hi hissa hua yeh kyuki repeat toh
                // karna ni hai
                if (helper.empty()) {
                    ans += curr;
                } else {
                    // varna koi aur pdha hoga usko sath m add krdo
                    helper.top().second += curr;
                }
            } else if (s[i] == ']') {
                int times = helper.top().first;
                string curr = "";
                while (times--) {
                    curr += helper.top().second;
                }
                helper.pop();

                if(helper.empty()){
                    ans+=curr;
                }
                else{
                    helper.top().second+=curr;
                }
                i++;
            }
            else i++;
        }
        return ans;
    }
};