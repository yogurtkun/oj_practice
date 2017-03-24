class Solution {
public:
    bool isValid(string s) {
        if (s.length() <= 0) 
            return true;
        stack<char> mystack;
        for (int i = 0; i < s.length(); i++)
        {
            if(!mystack.empty())
            {
                char tmp = mystack.top();
                if ((tmp == '(' && s[i] == ')') || (tmp == '[' && s[i] == ']') || (tmp == '{' && s[i] == '}'))
                    mystack.pop();
                else
                    mystack.push(s[i]);
            }
            else
                mystack.push(s[i]);
        }
        return mystack.empty();
    }
};
