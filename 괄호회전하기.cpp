#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

bool check(string s)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '{' or s[i] == '(' or s[i] == '[')
            st.push(s[i]);
        else if (s[i] == '}')
        {
            if (!st.empty() and st.top() == '{')
                st.pop();
            else
                return false;
        }
        else if (s[i] == ')')
        {
            if (!st.empty() and st.top() == '(')
                st.pop();
            else
                return false;
        }
        else if (s[i] == ']')
        {
            if (!st.empty() and st.top() == '[')
                st.pop();
            else
                return false;
        }
    }

    if (st.empty())
        return true;
    else
        return false;
}

char convert(char c)
{
    if (c == '{')
        return '}';
    else if (c == '}')
        return '{';
    else if (c == '(')
        return ')';
    else if (c == ')')
        return '(';
    else if (c == '[')
        return ']';
    else
        return '[';
}

int solution(string s)
{
    int answer = 0;

    int a = 0;
    int b = 0;
    int c = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '{')
            a++;
        else if (s[i] == '}')
            a--;
        else if (s[i] == '(')
            b++;
        else if (s[i] == ')')
            b--;
        else if (s[i] == '[')
            c++;
        else
            c--;
    }
    if (!(a == 0 and b == 0 and c == 0))
        return 0;

    int size = s.size();
    for (int i = 0; i < size; i++)
    {
        if (check(s))
            answer++;
        char c = convert(s[0]);
        s = s.substr(1) + s[0];
    }

    return answer;
}