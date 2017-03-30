class Solution {
public:
    string convert(string s, int numRows) {
        string result;
        if(numRows == 1) return s;
        int period = 2*numRows-2;
        int turn = s.length()/period;
        for(int pos = 0 ; pos < numRows ; pos++){
            string temp;

            if(pos == 0){
                for (int i = 0; i < turn+1; ++i)
                {
                    if( i * period < s.length() )
                        temp.push_back(s[i * period]);
                }
            }else if (pos == numRows - 1){
                for(int i = 0; i < turn+1; ++i)
                {
                    if( i * period + numRows - 1 < s.length() )
                        temp.push_back(s[i * period + numRows - 1]);
                }                
            }else{
                for(int i = 0 ; i < turn + 1 ; i ++){
                    if (i * period + pos < s.length())
                    {
                        temp.push_back(s[i * period + pos]);
                    }
                    if( i * period + numRows - 1 + numRows - 1 - pos < s.length()){
                        temp.push_back(s[i*period + 2*numRows - 2 -pos]);
                    }
                }
            }

            result += temp;
        }
        return result;
    }
};