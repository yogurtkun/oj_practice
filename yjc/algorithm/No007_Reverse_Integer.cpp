#include <cstdio>
#include <iostream>

using namespace::std;

class Solution {
public:
    int reverse(int x) {
        int ori = x;
        double result = 0;
        int data[34] = {};
        int pos = 0;
        while(abs(x) > 0){
            data[pos] = x % 10;
            x /= 10;
            pos ++;
        }

        for(int i = 0 ; i < pos ; i++){
            result *= 10;
            result += data[i]; 
            if(result - int(result) > 1 || result - int(result) < -1)
                return 0;    
        }

        return result;

    }
};

int main(){
    Solution s;
    int x = 1534236469;
    cout << s.reverse(x) << endl;
    

}