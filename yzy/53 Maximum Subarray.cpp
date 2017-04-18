class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        return find_sub(nums, low, high);
    }
    int find_sub(vector<int>& nums, int low, int high)
    {
        int left_sum = 0;
        int right_sum = 0;
        int cross_sum = 0;
        if(high == low)
            return nums[low];
        else 
        {
            int mid = (low + high) / 2;
            left_sum = find_sub(nums, low, mid);
            right_sum = find_sub(nums, mid+1, high);
            cross_sum = find_cross(nums, low, mid, high);
            if(right_sum >= cross_sum && right_sum >= left_sum)
                return right_sum;
            else if(left_sum >= right_sum && left_sum >= cross_sum)
                return left_sum;
            else
                return cross_sum;
        }
    }
    
    int find_cross(vector<int> &nums, int low, int mid, int high)
    {
        int left_sum = INT_MIN;
        int sum = 0;
        for (int i = mid; i >= low; i--)
        {
            sum += nums[i];
            if(sum > left_sum)
                left_sum = sum;
        }
        int right_sum = INT_MIN;
        sum = 0;
        for (int i = mid + 1; i <= high; i++)
        {
            sum += nums[i];
            if(sum > right_sum)
                right_sum = sum;
        }
        return left_sum + right_sum;
    }
};