#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cstring>
using namespace std;

map<string, int> name;
map<string, string> par;

void splitMoney(string s, int money)
{
    string parent = par[s];
    if (money < 10)
    {
        name[s] += money;
        return;
    }
    name[s] += money - money / 10;
    splitMoney(parent, money / 10);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount)
{
    vector<int> answer;
    for (int i = 0; i < enroll.size(); i++)
        name.insert(pair<string, int>(enroll[i], 0));
    for (int i = 0; i < referral.size(); i++)
        par.insert(pair<string, string>(enroll[i], referral[i]));

    for (int i = 0; i < seller.size(); i++)
    {
        string name = seller[i];
        splitMoney(name, amount[i] * 100);
    }

    for (int i = 0; i < enroll.size(); i++)
    {
        answer.push_back(name[enroll[i]]);
    }
    // 조직 구도 트리 생성

    // 수익별로 추천인에게 분배

    return answer;
}