#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace::std;

class Solution {
public:
    int romanToInt(string s) {
        char c[10] = {'M','D','C','L','X','V','I'};
        int v[10] = {1000,500,100,50,10,5,1};

        int c2v[300] = {};
        for(int i = 0 ; i < 7 ; i++){
            c2v[c[i]] = v[i];
        }

        int res = 0;
        int last = 0;
        for(int i = s.length()-1 ; i >= 0 ; i --){
            if(c2v[s[i]] >= last){
                res += c2v[s[i]];
                last = max(last,c2v[s[i]]);
            }else{
                res -= c2v[s[i]];
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    while(true){
        string l;
        cin >> l;
        cout << s.romanToInt(l) << endl;
    }
    return 0;
}