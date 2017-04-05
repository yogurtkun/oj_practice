class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1;
        int tar = m + n - 1;
        while(j >= 0)
        {
           
            if(nums1[i] > nums2[j] && i >= 0)
            {
                nums1[tar] = nums1[i];
                i--;
            }
            else
            {
                nums1[tar] = nums2[j];
                j--;
            }
           tar--;
        }
        /*while(j >= 0)
        {
            nums1[tar] = nums2[j];
            tar--;
            j--;
        }
        */
    }
};