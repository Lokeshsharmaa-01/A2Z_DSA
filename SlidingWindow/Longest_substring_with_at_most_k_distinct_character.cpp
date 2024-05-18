 // Brute Force
 // in this approch we will generate all possible substring with k distinct character
 // for distinct character we use map data structure 
 
 int longestKSubstr(string s, int k) {
    // your code here
        int maxlen = 0;
        unordered_map<char,int> mpp;
        for(int i= 0; i<s.size(); i++){
            mpp.clear(); // clear map in every itration
            for(int j = i ; j<s.size(); j++){
                mpp[s[j]]++;
                if(mpp.size() <= k){
                    maxlen = max(maxlen, j-i+1);
                }else break;
            }
        }
        return maxlen;
 }


 // Optimal/Better
 // in this approch we trim down all left similar character

int longestKSubstr(string s, int k){
    int maxlen = 0;
    int left =0, right = 0;
    unordered_map<char,int> mpp;
    while(right < s.size()){
        mpp[s[right]]++;
        while (mpp.size() > k) // for optimal we use if insted of while
        {
            mpp[s[left]]--;
            if(mpp.size() == 0) mpp.clear(mpp[s[left]]);
            left++;
        }
        if(mpp.size() <= k){
            maxlen = max(maxlen, right-left+1);
        }
        
    }
    return maxlen;
}
