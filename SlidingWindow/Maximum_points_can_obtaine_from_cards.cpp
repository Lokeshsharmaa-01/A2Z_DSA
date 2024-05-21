int maxpoints(vector<int> & arr , int k){
    int lsum = 0, rsum = 0;
    for(int i = 0; i<k; i++) lsum += arr[i];

    int maxsum = lsum;
    int rindex = arr.size() -1;
    for(int j = k-1; j>=0; j-- ){
        lsum = lsum - arr[j];
        rsum = rsum + arr[rindex];
        rindex--;
        maxsum = max(maxsum,lsum+rsum);
    }
    return maxsum;
}