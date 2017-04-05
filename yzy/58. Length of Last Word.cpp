//58. Length of Last Word
//水题刷自信
class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        if(s == "")
            return 0;
        int length = s.length();
        for (int i = 0; i < length; i++)
        {
            if(s[i] != ' ') 
                count++;
            else if((s[i] == ' ') && (s[i+1] != ' ') && ((i+1) < length))
                count = 0;
            //cout << count << endl;
        }
        return count;
    }
};