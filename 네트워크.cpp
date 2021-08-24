#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define MAX 201
int N;
bool visited[MAX];

void bfs(int ver, int n, vector<vector<int>> v)
{
    queue<int> q;
    q.push(ver);
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && v[front][i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            bfs(i, n, computers);
            answer++;
        }
    }
    return answer;
}