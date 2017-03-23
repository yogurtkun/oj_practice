class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> results;
        for (int i = 0; i < nums.size(); i++)
            results.push_back(nums[i]);
        //cout << results[0] << results[1] << endl;
        sort(results.begin(), results.end());
        //cout << results[0] << results[1] << endl;
        //cout << results.size() << endl;
        int l = 0;
        int h = results.size() - 1;
        //cout << l << h << endl;
        vector<int> index;
        while(l < h)
        {
            if (results[l] + results[h] > target)
                h--;
            else if(results[l] + results[h] < target)
                l++;
            else
                break;
        }
        //cout << l << " " << h;
        bool flag = true;
        for (int i = 0; i < nums.size(); i++)
        {
            if (results[l] == nums[i] && flag == true)
            {
                index.push_back(i);
                flag = false;
            }
            else if (results[h] == nums[i])
                index.push_back(i);
        }
        return index;
    }
};