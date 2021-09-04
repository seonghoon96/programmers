#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int> p1, pair<string, int> p2)
{
    if (p1.second > p2.second)
        return true;
    else
        return false;
}

map<string, int> dic;

void DFS(string s, string course, int index, int len)
{
    if (len == course.size())
    {
        dic[course]++;
        return;
    }
    for (int i = index; i < s.size(); i++)
    {
        course[len] = s[i];
        DFS(s, course, i + 1, len + 1);
    }
}

vector<string> solution(vector<string> orders, vector<int> course)
{

    vector<string> answer;
    for (int i = 0; i < orders.size(); i++)
        sort(orders[i].begin(), orders[i].end());

    for (int i = 0; i < orders.size(); i++)
    {
        string s = orders[i];
        for (int j = 0; j < course.size(); j++)
        {
            string cmb = "";
            cmb.resize(course[j]);
            DFS(s, cmb, 0, 0);
        }
    }

    vector<pair<string, int>> v;

    for (auto &str : dic)
    {
        if (str.second > 1)
            v.push_back(make_pair(str.first, str.second));
    }
    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < course.size(); i++)
    {
        int max = 0;
        for (int j = 0; j < v.size(); j++)
        {
            if (v[j].first.size() != course[i])
                continue;
            else if (max == 0)
            {
                answer.push_back(v[j].first);
                max = v[j].second;
            }
            else if (max == v[j].second)
            {
                answer.push_back(v[j].first);
            }
            else
                break;
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
}