#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace::std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int s = 0, e = height.size()-1;
        int max_area = min(height[s],height[e]) * (e-s);
        while(s<e){
            if(height[s] <= height[e]){
                s ++;
            }else{
                e --;
            }
            max_area = max(max_area,min(height[s],height[e]) * (e-s));
        }
        return max_area;
    }
};

int main(){
    Solution s;
    int test[10] = {1,2};
    vector<int> list(test,test+2);
    cout << s.maxArea(list) << endl;
    return 0;
}