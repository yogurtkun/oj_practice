#include <iostream>
#include <cstdio>
#include <vector>

using namespace::std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0){
            return false;
        }else if(x == 0){
            return true;
        }else{
            int y = 0,o = x;
            while(o / 10 > 0){
                y *= 10;
                y += (o%10);
                o /= 10;
            }
            y *= 10;
            y += o;
            return y==x;
        }
    }
};

int main(){
    Solution s;
    while(true){
        int a;
        cin >> a;
        cout << s.isPalindrome(a) << endl;
    }

}