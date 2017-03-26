class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
        if (length <= 0)
            return 0;
        int i = 0, j = 0;
        while(j < length-1)
        {
            if(nums[j+1] == nums[j])
                j++;
            else
            {
                nums[i+1] = nums[j+1];
                i++;
                j++;
            }
        }
        //cout<<length;
        return i+1;
    }
};