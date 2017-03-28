class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int length = nums.size();
        int low = 0, high = length-1;
        int mid = 0;
        while(low <= high)
        {
            mid = (low + high) / 2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target) 
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
             /*
        if (length <= 0)
            return 0;
        int i = 0;
        int flag = 0;
        for (i = 0; i < length; i++)
        {
           // cout << i << endl;
            if(nums[i] == target)
            {
                flag = 1;
                return i;
            }
        }
        if (!flag)
        {
            for (int j = 0; j < length; j++)
            {
               // cout << j << endl;
                if(nums[0] > target)
                    return 0;
                else if(j == length - 1)
                    return length;
                else if((nums[j] < target) && (nums[j+1] > target))
                    return j+1;
            }
        }
        */
    }
};