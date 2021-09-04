#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct
{
    vector<pair<int, int>> list;
    int total;
} genr;

map<string, genr> dic;

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;
    for (int i = 0; i < genres.size(); i++)
    {
        if (dic[genres[i]].list.empty())
        {
            dic[genres[i]].total = plays[i];
            dic[genres[i]].list.push_back({-plays[i], i});
        }
        else
        {
            dic[genres[i]].total += plays[i];
            dic[genres[i]].list.push_back({-plays[i], i});
        }
    }

    vector<pair<int, string>> totallist;
    for (auto &[key, genr] : dic)
    {
        totallist.push_back({genr.total, key});
        sort(genr.list.begin(), genr.list.end());
    }
    sort(totallist.begin(), totallist.end());
    for (int i = totallist.size() - 1; i >= 0; i--)
    {
        string gen = totallist[i].second;
        int count = 0;
        for (int i = 0; i < dic[gen].list.size(); i++)
        {
            answer.push_back(dic[gen].list[i].second);
            count++;
            if (count == 2)
                break;
        }
    }

    return answer;
}