// it is simple 
// first we sort the both array
// then we took two pointer one is indicates to greed and second point to s
// then we check for if greed[r] <= s[l] then we increase the r value
// and then l value untill loop ends


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n = g.size();
        int m = s.size();
        int l = 0;
        int r = 0;
        while(l<m && r<n){
            if(g[r] <= s[l]) r= r+1;
            l = l +1;
        }
        return r;
    }
};