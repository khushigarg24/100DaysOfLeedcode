//680. Valid Palindrome II
class Solution {
public:
    bool isPallindrome(string s,int i,int j){
        while(i<j){
            if(s.at(i)==s.at(j)){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s.at(i)==s.at(j)){
                i++;
                j--;
            }
            else{
                return isPallindrome(s,i+1,j) || 
                isPallindrome(s,i,j-1);
            }
        }
        return true;
    }
};


//684. Redundant Connection
class Solution {
public:
int findParent(int n,vector<int>p){
    if(n==p[n]){
        return n;
    }
    return findParent(p[n],p);
}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>parent(1001,0);
        for(int i=0;i<parent.size();i++){
            parent[i]=i;
        }
        vector<int>res;
        for(auto v:edges){
            int n1=v[0], n2=v[1];
            int p1=findParent(n1,parent);
            int p2=findParent(n2,parent);
            if(p1==p2){
                res=v;
            }
            parent[p1]=p2;
        }
        return res;
    }
};