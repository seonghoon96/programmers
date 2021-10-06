#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(string s)
{
    int minLen = s.size() * 2;
    if (s.size() == 1)
        return 1;
    for (int i = 1; i < s.size(); i++)
    {
        string result;
        if (true)
        {
            string tmp1 = s.substr(0, i);
            int tmp_cnt = 1;
            for (int j = i; j < s.size(); j += i)
            {
                string tmp2 = s.substr(j, i);
                if (tmp1 == tmp2)   
                {
                    tmp_cnt++;
                    continue;
                }
                else
                {
                    if (tmp_cnt == 1)
                        result += tmp1;
                    else
                        result += to_string(tmp_cnt) + tmp1;
                    tmp1 = tmp2;
                    tmp_cnt = 1;
                }
            }
            if (tmp_cnt == 1)
                result += tmp1;
            else
                result += to_string(tmp_cnt) + tmp1;
            tmp_cnt = 1;
            if (minLen > result.size())
                minLen = result.size();
        }
    }
    return minLen;
}