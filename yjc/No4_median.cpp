#include <cstdio>
#include <iostream>
#include <vector>

using namespace::std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l_1 = nums1.size();
        int l_2 = nums2.size();

        if( (l_1+l_2) % 2 ==1 ){
            return float(getkthnumber(nums1,nums2,(l_1+l_2+1)/2));
        }else{
            return (float(getkthnumber(nums1,nums2,(l_1+l_2+1)/2)) + float(getkthnumber(nums1,nums2,(l_1+l_2+2)/2)))/2;
        }
        

    }

    int getkthnumber(vector<int>& nums1, vector<int>& nums2,int k){
        int n1_s = 0, n1_e = nums1.size();
        int n2_s = 0, n2_e = nums2.size();

        while(true){
            if(n1_s == n1_e){
                return nums2[n2_s + k - 1];
            }else if(n2_s == n2_e){
                return nums1[n1_s + k - 1];
            }else if(k == 1){
                return min(nums1[n1_s],nums2[n2_s]);
            }

            if( (n1_e - n1_s)/2 + (n2_e - n2_s)/2 >= k ){
                cout << 5 << endl;
                if( nums1[n1_s+(n1_e - n1_s)/2] > nums2[n2_s+(n2_e - n2_s)/2] ){
                    n1_e -= (n1_e - n1_s+1)/2;
                }else{
                    n2_e -= (n2_e - n2_s+1)/2;
                }
            }else{
                int n1_add = 0, n2_add = 0;
                if((n1_e - n1_s)/2 == 0){
                    n1_add = 1;              
                } 
                if((n2_e - n2_s)/2 == 0){
                    n2_add = 1;          
                }
                if( nums1[n1_s+(n1_e - n1_s)/2-1 + n1_add] > nums2[n2_s+(n2_e - n2_s)/2-1 + n2_add] ){
                    k -= (n2_e - n2_s + n2_add)/2;
                    n2_s = n2_s + (n2_e - n2_s)/2 + n2_add;
                }else{
                    k -= (n1_e - n1_s + n1_add)/2;
                    n1_s = n1_s + (n1_e - n1_s)/2 + n1_add;
                }
            }
        }
    }

};

int main(){
    int d[] = {1,2};
    int e[] = {3,4};
    vector<int> a(d,d+2);
    vector<int> b(e,e+2);

    Solution s;

    cout << s.getkthnumber(a,b,3) << endl;
}