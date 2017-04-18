#include <iostream>
#include <cstdio>
#include <string>

using namespace::std;

class Solution {
public:
    int myAtoi(string str) {
        int result = 0;
        int old_result = 0;
        int len = str.length();
        bool start = false;
        int sign = 0;
        for(int i = 0 ; i < len ; i++){
            if(start){
                if(!isdigit(str[i]))
                    break;
                else{
                    old_result = result;
                    result *= 10;
                    if(sign == 0)
                        result += (str[i]-'0');
                    else
                        result -= (str[i]-'0');
                    if(result/10 != old_result)
                        return (sign == 0)?0x7fffffff:0x80000000;
                }
            }else{
                if(str[i] == '-'){
                    sign = 1;
                    start = true;
                }else if(str[i] == '+'){
                    sign = 0;
                    start = true;
                }else if(isdigit(str[i])){
                    start = true;
                    result += (str[i]-'0');
                }else if(str[i] == ' '){
                    continue;
                }else{
                    return 0;
                }
            }
        }
        return result;
    }

    bool isdigit(char c){
        if( c <= '9' && c >= '0' )
            return true;
        else
            return false;
    }
};

int main(){
    Solution s;
    string x("   012");
    cout << s.myAtoi(x) << endl;
}