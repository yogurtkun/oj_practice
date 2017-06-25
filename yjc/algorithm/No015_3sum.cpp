#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace::std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector< vector<int> > res;

        sort(nums.begin(),nums.end());

        for(int i = 0; i < nums.size(); i++){
            int j = i+1;
            int k = nums.size()-1;
            while(j<k)
            {
                if( nums[i]+nums[j]+nums[k] < 0 ){
                    j++;
                }else if(nums[i]+nums[j]+nums[k] == 0 ){
                    vector<int> t ({nums[i],nums[j],nums[k]});
                    res.push_back(t);
                    while(nums[j+1]==nums[j] && j<k) j++;j++;
                    while(nums[k-1]==nums[k] && j<k) k--;k--;
                }else{
                    k--;
                }
            }
            while(i<nums.size()-1){
                int temp = i+1;
                if(nums[temp] == nums[i])
                    i++;
                else
                    break;
            }
        }

        return res;
    }
};

int main(){
    Solution s;
    int num[10] = {-1, 0, 1, 2, -1, -4};
    vector<int> S(num,num+6);
    // for(auto i = S.begin(); i != S.end() ; i++){
    //     cout << *i << endl;
    // }
    vector<vector<int>> res = s.threeSum(S);
    for(auto i = res.begin() ;i != res.end();i ++ ){
        for(auto j = (*i).begin(); j != (*i).end(); j ++ ){
            cout << (*j) << " ";
        }
        cout << endl;
    }
}