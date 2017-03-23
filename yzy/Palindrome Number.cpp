class Solution {
public:
    bool isPalindrome(int x) {
        const int max = 0x7fffffff;
        if (x < 0)
            return false;
        else if (x == 0)
            return true;
        else
        {
            long long sum = 0;
            int y = x;
            //cout << y << endl;
            while(y != 0)
            {
                int tmp = y % 10;
                sum = sum * 10 + tmp;
                y = y / 10;
            }
            cout << sum << endl;
            if (sum > max)
                return false;
            else if (sum == x)
                return true;
            else
                return false;
        }
    }
};