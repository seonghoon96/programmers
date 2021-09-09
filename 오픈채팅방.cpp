#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

vector<string> solution(vector<string> record)
{
    vector<string> answer;
    vector<pair<string, string>> m;
    map<string, string> graph;
    for (int i = 0; i < record.size(); i++)
    {
        stringstream ss(record[i]);
        string move, uid, name;
        ss >> move >> uid;
        m.push_back({move, uid});
        if (move == "Leave")
            continue;
        ss >> name;
        graph[uid] = name;
    }
    for (int i = 0; i < m.size(); i++)
    {
        string str = "";
        str += graph[m[i].second];
        if (m[i].first == "Enter")
            str += "님이 들어왔습니다.";
        else if (m[i].first == "Leave")
            str += "님이 나갔습니다.";
        else
            continue;
        answer.push_back(str);
    }
    return answer;
}