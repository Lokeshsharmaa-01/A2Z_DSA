 // Brute Force
 // in this approch we will generate all possible substring with k distinct character
 // for distinct character we use map data structure 
 
 int longestKSubstr(string s, int k) {
    // your code here
        int maxlen = 0;
        unordered_map<char,int> mpp;
        for(int i= 0; i<s.size(); i++){
            mpp.clear(); // clear map every time
            for(int j = i ; j<s.size(); j++){
                mpp[s[j]]++;
                if(mpp.size() <= k){
                    maxlen = max(maxlen, j-i+1);
                }else break;
            }
        }
        return maxlen;
 }