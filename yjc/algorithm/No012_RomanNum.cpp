#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace::std;

class Solution {
public:
    string intToRoman(int num) {
        char c[10] = {'M','D','C','L','X','V','I'};
        int v[10] = {1000,500,100,50,10,5,1};
        
        string res;

        for(int i = 0 ;i < 7 ; i+=2){
            int div = num/v[i];
            num %= v[i];
            if(div < 4 && div > 0){
                res.append(div,c[i]);
            }else if(div == 4){
                res.append(1,c[i]);
                res.append(1,c[i-1]);
            }else if(div > 4 && div < 9){
                res.append(1,c[i-1]);
                res.append(div-5,c[i]);
            }else if(div == 9){
                res.append(1,c[i]);
                res.append(1,c[i-2]);
            }
        }

        return res;
    }
};


int main(){
    Solution s;
    while(true){
        int n;
        cin >> n;
        cout << s.intToRoman(n) << endl;
    }
    return 0;
}