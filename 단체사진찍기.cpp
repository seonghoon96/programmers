#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

char posa, posb, op;
int dis;
vector<char> v;
map<char, int> dic;
int solution(int n, vector<string> data)
{
    int answer = 0;

    v.push_back('A');
    v.push_back('C');
    v.push_back('F');
    v.push_back('J');
    v.push_back('M');
    v.push_back('N');
    v.push_back('R');
    v.push_back('T');
    do
    {
        for (int i = 0; i < v.size(); i++)
            dic[v[i]] = i;
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            string cd = data[i];
            posa = cd[0];
            posb = cd[2];
            op = cd[3];
            dis = cd[4] - '0';
            // auto it1 = find(v.begin(), v.end(), posa) - v.begin();
            // auto it2 = find(v.begin(), v.end(), posb) - v.begin();
            int it1 = dic[posa];
            int it2 = dic[posb];
            if (op == '=')
            {
                if (abs(it1 - it2) - 1 == dis)
                    continue;
                else
                    flag = false;
            }
            else if (op == '>')
            {
                if (abs(it1 - it2) > dis + 1)
                    continue;
                else
                    flag = false;
            }
            else if (op == '<')
            {
                if (abs(it1 - it2) < dis + 1)
                    continue;
                else
                    flag = false;
            }
            if (flag == false)
                break;
        }
        if (flag == true)
            answer++;
    } while (next_permutation(v.begin(), v.end()));

    return answer;
}