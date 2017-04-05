class Solution {
public:
    int mySqrt(int x) {
        for(int i = 0;i <= 46340; i++)
        {
            if(i * i <= x && x < (i+1) * (i+1))
            {
                return i;
            }    
        }
        return 46340;
   
    }
};