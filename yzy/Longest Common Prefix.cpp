class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int num = strs.size();
        if(num<=0) return ""; //boundary
        string X = strs[0];
        for (int i = 1; i < num; i++)
        {
            int j = 0;
            while(j <= strs[i].length()) //boundary, need one more step to get substr
            {
                if(strs[i][j] == X[j] && j <= strs[i].length() - 1)
                {
                    j++;
                }
                
                else 
                {
                    j--;
                    X = X.substr(0,j+1); //substr(begin, length)
                    break;
                }
            }
        }
        return X;
    }
};