#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace::std;
/*********
另一个解法是比较所有字符串和第一个的最长子串，然后取最小值
*********/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return string("");
        string min_s = *min_element(strs.begin(),strs.end(),&Solution::func);
        int min_l = min_s.length();
        string result("");
        for(int i = 0 ; i < min_l ; i ++){
            bool same = true;
            char f_c = strs[0][i];
            for(int j = 1 ; j < strs.size() ; j ++){
                if(strs[j][i] != f_c)
                    same = false;
            }
            if(same)
                result.push_back(f_c);
            else
                break;
        }

        return result;

    }
    static bool func(string s1,string s2){
        return s1.length() < s2.length();
    }
};

int main(){
    Solution s;
    // string test[10] = {string("aaab"),string("aab"),string("aaac")};
    string test[10] = {};
    // vector<string> c(test,test+3);
    vector<string> c;
    cout << s.longestCommonPrefix(c) << endl;
}