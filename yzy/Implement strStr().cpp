class Solution {
public:
    int strStr(string haystack, string needle) {
        int l1 = haystack.length();
        int l2 = needle.length();
        if (l2 == 0)
            return 0;
        int i = 0, j = 0;
        int flag = false;
        int index = -1;
        int old_index = 0;
        while((i < l1) && (j < l2) && (l1 >= l2))
        {
            if (haystack[i] == needle[j] && i != index)
            {
                if(flag == false)
                {
                    index = i;
                    flag = true;
                }
                i++;
                j++;
            }
            else
            {
                if(flag == true)
                {
                    flag = false;
                    j = 0;
                    i = index+1; 
                    //index = i;
                }
                else
                    i++;
            }
            //cout << i << " " << j << " "<<  index << " " << flag << endl;
        }
        if(flag && (j == l2))
            return index;
        else
            return -1;
    }
};