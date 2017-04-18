class Solution {
public:
    string addBinary(string a, string b) {
        int l1 = a.length();
        int l2 = b.length();
        int max = 0;
        if(l1 >= l2)
            max = l1;
        else
            max = l2;
        char c[max];
        int x = 0;
        //cout << max <<endl;
        for (int i = max - 1; i >= 0; i--)
        {
            if(i < l1 && i < l2)
            {
                if(a[i] - '0' + b[i] - '0' + x == 3)
                {
                    c[i] = '1';
                    x = 1;
                }
                else if(a[i] - '0' + b[i] - '0' + x == 2)
                {
                    c[i] = '0';
                    x = 1;
                }
                else if(a[i] - '0' + b[i] - '0' + x == 1)
                {
                    c[i] = '1';
                    x = 0;
                }
                else 
                {
                    //cout << "ffff" <<endl;
                    c[i] = '0';
                    x = 0;
                }
            }
            else if(i >= l1 && i < l2)
                c[i] = b[i];
            else if(i < l1 && i >= l2)
                c[i] = a[i];
        }
       // string d = c;
        //return d;
        return c;
    }
};