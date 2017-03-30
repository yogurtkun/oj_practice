/*****
一种更快速的方法：
对于n个字母有2n-1个中心对称点，所以可以从者2n-1个点进行扩展来比较
虽然也是O(n)复杂度，但是有常数优化
******/
class Solution { 
public:
    string longestPalindrome(string s) {
        int mat[1000][1000] = {};
        int len = s.length();
        int max_l = 1;
        int s_c = 0,e_c = 0;

        for(int i = 0 ; i < len - 1; i++){
            if(s[i] == s[i+1]){
                mat[i][i+1] = 2;
                max_l = 2;
                s_c = i;
                e_c = i+1;
            }
            else
                mat[i][i+1] = 0;
        }
        for(int i = 0 ; i < len ; i ++){
            mat[i][i] = 1;
        }

        for(int l = 3 ; l <= len ; l ++){
            for(int f = 0 ; f <= len - l ; f ++){
                if(s[f] == s[f+l-1] && mat[f+1][f+l-2] != 0){
                    mat[f][f+l-1] = mat[f+1][f+l-2] + 2;
                    if(mat[f][f+l-1] > max_l){
                        max_l = mat[f][f+l-1];
                        s_c = f;
                        e_c = f+l-1;
                    }
                }
            }
        }

        return string(s.begin()+s_c,s.begin()+e_c+1);
        
    }
};