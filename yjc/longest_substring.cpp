/*******
Its runtime beats 89.49% of cpp submissions
********/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;
        int pos[300] = {};

        int now_len = 0;

        int j = 0;
        for(int i = 0 ; i < s.length() ; i++){
            for(; j < s.length() ; j++){
                if( !pos[s[j]] ){
                    pos[s[j]] = 1;
                    now_len += 1;
                }else{
                    max_length = max(now_len,max_length);
                    pos[s[i]] = 0;
                    now_len -= 1;
                    break;
                }
            }
        }

        return max(max_length,now_len);

    }
};