//66. Plus One
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        cout << size << endl;
        for(int i = size - 1; i >= 0; i--)
        {
            if(digits[i] + 1 <= 9)
            {
                digits[i] += 1;
                break;
            }
            else
                digits[i] = 0;
        }
        if(digits[0] != 0)
            return digits;
        else
        {
            vector<int> digit;
            digit.push_back(1);
            for(int i = 1; i <= size; i++)
                digit.push_back(0);
            return digit;                    
        }
        return digits;
    }
};