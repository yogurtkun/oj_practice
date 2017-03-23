class Solution {
public:
    int reverse(int x) {
        long long sum = 0;
        const int max = 0x7fffffff;
        const int min = 0x80000000;
        while(x != 0)
        {
            int tmp = x % 10;
            sum = sum * 10 + tmp;
            if (sum > max ||sum < min)
            {
                sum = 0;
            }
            x = x / 10;
        }
        return sum;
    }
};