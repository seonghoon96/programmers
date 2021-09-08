#include <string>
#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

deque<int> dq;
vector<int> solution(vector<string> operations)
{
    vector<int> answer;

    for (int i = 0; i < operations.size(); i++)
    {
        string op = operations[i];
        if (op.substr(0, 1) == "I")
        { // 큐에 주어진 숫자 삽입
            cout << "insert" << endl;
            int value = stoi(op.substr(2));
            dq.push_back(value);
            sort(dq.begin(), dq.end());
        }
        else if (op == "D 1")
        { // 최댓값 삭제
            cout << "max" << endl;
            // 큐가 비었을 경우 무시
            if (!dq.empty())
            {
                dq.pop_back();
            }
        }
        else
        { // 최솟값 삭제
            cout << "min" << endl;
            // 큐가 비었을 경우 무시
            if (!dq.empty())
            {
                dq.pop_front();
            }
        
    }

    if (!dq.empty())
    {
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }
    else
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}