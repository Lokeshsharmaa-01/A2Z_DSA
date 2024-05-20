Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]









// in this approch we doing something different from given question
// 



class Solution
{
public:
    int helper(vector<int> &nums, int goal)
    {
        int l = 0, r = 0, cnt = 0, sum = 0;
        if (goal < 0)
            return 0;
        while (r < nums.size())
        {
            sum += nums[r];
            while (sum > goal)
            {
                sum = sum - nums[l];
                l = l + 1;
            }
            cnt += (r - l + 1);
            r = r + 1;
        }
        return cnt;
    }

    int numSubarraysWithSum(vector<int> &nums, int goal)
    {

        return helper(nums, goal) - helper(nums, goal - 1);
    }
};