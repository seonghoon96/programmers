#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cstring>
using namespace std;

map<string, int> dic;
map<string, string> parent;

void splitMoney(string seller, int pay)
{
    if (pay < 10 or seller == "-")
    {
        dic[seller] += pay;
        return;
    }
    dic[seller] += pay - pay / 10;
    splitMoney(parent[seller], pay / 10);
}
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount)
{
    vector<int> answer;
    for (int i = 0; i < enroll.size(); i++)
    {
        parent[enroll[i]] = referral[i];
        dic[enroll[i]] = 0;
    }
    for (int i = 0; i < seller.size(); i++)
        splitMoney(seller[i], amount[i] * 100);

    for (int i = 0; i < enroll.size(); i++)
        answer.push_back(dic[enroll[i]]);

    return answer;
}
