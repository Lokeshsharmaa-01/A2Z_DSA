int subStringWithoutRep(string s){
    vector<int> v(256,-1);
    int left = 0;
    int right = 0;
    int maxlen = 0;
    while(right < s.size()){
        if(v[s[right]] != -1){
            left = max(left,v[s[right]] +1);
        }
        v[s[right]] = right;
        maxlen = max(maxlen,right-left+1);
        right++;
    }
    return maxlen;
}