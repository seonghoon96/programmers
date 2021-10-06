#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

vector<vector<int>> v(101);

int BFS(int node, int nodex)
{
    int tower = 1;
    queue<int> q;
    q.push(node);
    bool visited[101];
    memset(visited, false, sizeof(visited));
    visited[node] = true;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (int i = 0; i < v[front].size(); i++)
        {
            if (v[front][i] == nodex)
                continue;
            else if (!visited[v[front][i]])
            {
                visited[v[front][i]] = true;
                tower++;
                q.push(v[front][i]);
            }
        }
    }
    return tower;
}

int solution(int n, vector<vector<int>> wires)
{
    int answer = n + 1;

    for (int i = 0; i < wires.size(); i++)
    {
        v[wires[i][0]].push_back(wires[i][1]);
        v[wires[i][1]].push_back(wires[i][0]);
    }

    for (int i = 0; i < wires.size(); i++)
    {
        int tower1, tower2;
        tower1 = wires[i][0];
        tower2 = wires[i][1];
        int value = BFS(tower1, tower2);
        value = abs(2 * value - n);
        answer = min(answer, value);
    }

    return answer;
}