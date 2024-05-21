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
            sum += nums[r]%2;
            while (sum > goal)
            {
                sum = sum - (nums[l]%2);
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