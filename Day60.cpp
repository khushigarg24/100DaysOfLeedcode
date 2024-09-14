//1431. Kids With the Greatest Number of Candies
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies=0;

        for(int i=0;i<candies.size();i++){
            maxCandies=max(maxCandies,candies[i]);
        }

        vector<bool> result(candies.size(),false);

        for(int i=0;i<candies.size();i++){
            if((candies[i]+extraCandies)>=maxCandies)result[i]=true;
        }

        return result;
    }
};


//1423. Maximum Points You Can Obtain from Cards
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int i=0;int j=cardPoints.size()-1;
        int ans=0;
        int temp=0;
        while(i<k){
            temp+=cardPoints[i];
            i++;
        }
        ans=temp;
        i--;
        while(i>=0){
            temp-=cardPoints[i];
            i--;
            temp+=cardPoints[j];
            j--;
            ans=max(ans,temp);
        }
        return ans;
    }
};