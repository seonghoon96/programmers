#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
#define MAX 20000 + 1
using namespace std;

bool visited[MAX];
int space[MAX][MAX];
int d[MAX];

int solution(int n, vector<vector<int>> edge)
{
    int answer = 0;
    memset(visited, false, sizeof(visited));
    memset(space, false, sizeof(space));
    for (int i = 0; i < edge.size(); i++)
    {
        space[edge[i][0]][edge[i][1]] = 1;
        space[edge[i][1]][edge[i][0]] = 1;
    }

    queue<pair<int, int>> q;
    visited[1] = true;
    q.push({1, 0});
    int maxDistance = 0;
    while (!q.empty())
    {
        int ver = q.front().first;
        int dis = q.front().second;
        q.pop();
        for (int i = 1; i <= n; i++)
        {
            if (space[ver][i] && !visited[i])
            {
                d[i] = dis + 1;
                maxDistance = max(maxDistance, d[i]);
                visited[i] = true;
                q.push({i, d[i]});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        //        cout << d[i] << " ";
        if (maxDistance == d[i])
            answer++;
    }
    return answer;
}