#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;
    int total = 0;
    int count = 0;
    queue<int> q;

    while (true)
    {
        answer++;
        if (q.size() == bridge_length)
        {
            total -= q.front();
            q.pop();
        }

        if (total + truck_weights[count] <= weight)
        {
            if (count == truck_weights.size() - 1)
            {
                answer += bridge_length;
                break;
            }
            q.push(truck_weights[count]);
            total += truck_weights[count];
            count++;
        }
        else
            q.push(0);
    }

    return answer;
}