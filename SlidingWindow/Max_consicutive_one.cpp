// brute force


int longestOnes(vector<int>& nums, int k) {

        int maxlen = 0, z = 0;
        
        for (int i = 0; i < n; i++)
        {
            z = 0;
            for(int j = i ; j<n; j++){
                if(nums[j] == 0) z++;
                if(z <= k) maxlen = max(maxlen, j-i+1);
                else break;

            }
        }
        
        return maxlen
}





// better

int longestOnes(vector<int>& nums, int k) {
        int maxlen = 0, left = 0, right = 0, z = 0;
        int n = nums.size();
        while(right < n){
            if(nums[right] == 0) z++;
            while(z > k){
                if( nums[left] == 0) z--;
                left++;
            }
            if( z <= k) {
                
                int len = right-left+1;
                maxlen = max(maxlen,len);
            }
            right++;
         }
        return maxl
}