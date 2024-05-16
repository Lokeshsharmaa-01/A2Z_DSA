// Brute force for this question is simple generate all possible subarray and find max length

// T.C -> N X N

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


// Better approch 

// <---------------- SLIDING WINDOW AND TWO POINTER --------------------->

// in this approch first we put element in map data structure for count occurens
// then we check if it's size is greater then 2 then we trim window from left
// if size is less then or equal to 2 we count the length 
// and at last we return the max len

int maxlength(int arr[]){
    int l = 0;
    int r = 0;
    int n = arr.size();
    int maxlen = 0;
    unordered_map<int,int> mpp;
    while (r<n)
    {
        mpp[arr[r]]++;
        if (mpp.size() > 2)
        {
            while(mpp.size() > 2){
                mpp[arr[r]]--;
                if(mpp[arr[l]] == 0) mpp.erase(arr[l]);
                l++;
            }
        }
        if(mpp.size() <= 2){
            maxlen = max(maxlen, r-l+1);
        }
        r++;
        
    }
    return maxlen;
    
}

// Optimal approch

// in this approch we don't use inner while loop for trimming window
// insted of while we just remove only one element from it

int maxlength(int arr[]){
    int l = 0;
    int r = 0;
    int maxlen = 0;
    int n = arr.size();
    unordered_map<int,int> mpp;
    while(r<n){
        mpp[arr[r]]++;
        if(mpp.size() > 2){
            mpp[arr[l]]--;
            if (mpp[arr[l]] == 0)
            {
                mpp.erase(arr[l]);
            }
            l++;
        }
        if (mpp.size() <=2)
        {
            maxlen = max(maxlen,r-l+1);
        }
        r++;
        
    }
    return maxlen;
}