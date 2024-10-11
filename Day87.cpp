//875. Koko Eating Bananas
class Solution {
public:
    bool canEatAll(vector<int>& piles, int givenHour, int h) {
        int actualHour = 0;

        for (int& x : piles) {
            actualHour += x / givenHour;

            if (x % givenHour != 0)
                actualHour++;
        }

        return actualHour <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int l = 1, r = *max_element(begin(piles), end(piles));

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (canEatAll(piles, mid, h)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};


//2300. Successful Pairs of Spells and Potions
class Solution {
public:
    int potionsCount(vector<int>& potions, long long spell, long long success) {
        long long start = 0;
        long long end = potions.size() - 1;
        long long mid = start + (end - start) / 2;
        long long ans=-1;
        while (start <= end) {
            mid = start + (end - start) / 2;
            if (spell * potions[mid] >= success) {
                ans = mid;
                end = mid - 1;
            } else if (spell * potions[mid] < success) {
                start = mid + 1;
            }
        }
        if (ans == -1) {
            return 0;
        }
        return potions.size() - ans;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        vector<int> pairs;
        sort(potions.begin(), potions.end());
        for (auto i : spells) {
            int ans = potionsCount(potions, i, success);
            pairs.push_back(ans);
        }
        return pairs;
    }
};