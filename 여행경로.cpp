#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
map<string, vector<pair<string, bool>>> ticket;
vector<string> answer;
vector<string> ans;
int answersize;
int ansflag = false;
void DFS(string s)
{

    if (answer.size() == answersize + 1 && ansflag == false)
    {
        ans = answer;
        ansflag = true;
        return;
    }

    for (int i = 0; i < ticket[s].size(); i++)
    {
        if (ticket[s][i].second == false)
        {
            ticket[s][i].second = true;
            answer.push_back(ticket[s][i].first);
            DFS(ticket[s][i].first);
            answer.pop_back();
            ticket[s][i].second = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets)
{
    answer.push_back("ICN");
    answersize = tickets.size();
    for (int i = 0; i < tickets.size(); i++)
        ticket[tickets[i][0]].push_back({tickets[i][1], false});
    for (auto &[key, value] : ticket)
        sort(value.begin(), value.end());

    DFS("ICN");

    return ans;
}