// Brute force for this question is simple generate all possible subarray and find max length



int maxlength(int arr[]){
    int n = 6;
    int maxlen = 0;
    for(int i = 0; i<n; i++){
        set<int> st;
        for(int j = i; j<n; j++){
            st.insert(arr[j]);
            if(st.size() <= 2){
                maxlen = max(maxlen, j-i+1);
            }else break;
        }
    }
    return maxlen;
}