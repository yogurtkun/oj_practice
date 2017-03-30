class Solution {
public:
    string countAndSay(int n) {
        string countAndSay = "1";
        if (n == 1)
            return countAndSay;
        else
        {
            for(int i = 2; i <= n; i++)
            {
                string newstring = "";
                char tmp = countAndSay[0];
                int num = 0;
                for (int k = 0; k < countAndSay.length(); k++)
                {
                    if(tmp == countAndSay[k])
                    {
                        num++;
                        continue; //跳过循环中剩余语句
                    }
                    //stringstream ss;
                    //ss << num;
                    //string s1 = ss.str();
                    newstring.append(to_string(num) + tmp);
                    tmp = countAndSay[k];
                    num = 1;
                }
                //stringstream s;
                //s << num;
                //string s2 = s.str();
                newstring.append(to_string(num)+tmp);
                countAndSay = newstring;
            }
            return countAndSay;
        }
    }
};