//190. Reverse Bits
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans=0;
        for(int i=0;i<32;i++){
            ans=ans<<1;
            ans=ans|(n&1);
            n>>=1;
        }
        return ans;
    }
};

//191. Number of 1 Bits
class Solution {
public:
    int hammingWeight(int n) {
        int one=0;
        while(n>0){
            one++;
            n=n&(n-1);
        }
        return one;
    }
};