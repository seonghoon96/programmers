#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;
bool check_balance(string s)
{
    stack<int> st;
    int index = 0;
    while (index < s.size())
    {
        if (s[index] == '(')
            st.push(1);
        else if (s[index] == ')')
        {
            if (!st.empty())
                st.pop();
            else
                return false;
        }
        index++;
    }
    if (st.empty())
        return true;
    else
        return false;
}

string first(string s)
{
    string u = "";
    string v = "";

    if (check_balance(s) == true)
        return s;
    else
    {
        int index = 0;
        int empty = 0;
        while (true)
        {
            if (s[index] == '(')
                empty += 1;
            else
                empty -= 1;
            index++;
            if (empty == 0)
                break;
        }
        u = s.substr(0, index);
        v = s.substr(index, s.size());
        if (check_balance(u))
            return u + first(v);
        else
        {
            string tmp = "(";
            tmp += first(v) + ")";
            u = u.substr(1, u.size() - 2);
            for (int i = 0; i < u.size(); i++)
            {
                if (u[i] == '(')
                    tmp += ')';
                else
                    tmp += '(';
            }
            return tmp;
        }
    }
}

string solution(string p)
{
    string answer = "";
    if (p.size() == 0)
        return "";

    return first(p);
}