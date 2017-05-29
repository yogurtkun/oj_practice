#include <iostream>
#include <cstdio>
#include <vector>

using namespace::std;

class Solution {
public:
    string str;
    string pattern;
    bool isMatch(string s, string p) {
        str = s;
        pattern = p;

        return dfs(0,0);
    }

    bool isCharMatch(int a = 0,int b = 0){
        if(b >= pattern.length() || a >= str.length())
            return false;

        if(pattern[b] == '*')
            b -= 1;

        if(pattern[b] == '.')
            return true;
        else if(str[a] == pattern[b])
            return true;
        else
            return false;

    }

    bool dfs(int a, int b){
        if(a == str.length() && b == pattern.length())
            return true;

        if(b < pattern.length()-1 && pattern[b+1] == '*')
            b += 1;
        
        bool result = isCharMatch(a,b);

        if(pattern[b] == '*'){
            if(result && dfs(a+1,b))
                return true;
            return dfs(a,b+1);
        }else{
            if(result){
                return dfs(a+1,b+1);
            }else{
                return false;
            }
        }
    }
};

int main(){
    Solution s;
    string s1,s2;
    while(true){
        cin >> s1 >> s2;
        cout << s.isMatch(s1,s2) << endl;
    }

}