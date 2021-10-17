#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define INF 987654321
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

vector<vector<int>> maps;
bool visited[100][100];
int answer = INF;
int r, c;

int BFS(int x, int y)
{
    visited[x][y] = true;
    queue<pair<pair<int, int>, int>> q;
    q.push({{x, y}, 1});
    while (!q.empty())
    {
        int xpos = q.front().first.first;
        int ypos = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        if (xpos == r - 1 and ypos == c - 1)
            return cnt;

        for (int i = 0; i < 4; i++)
        {
            int nx = xpos + dx[i];
            int ny = ypos + dy[i];
            if (0 <= nx and nx < r and 0 <= ny and ny < c)
            {
                if (visited[nx][ny] == false and maps[nx][ny] == 1)
                {
                    visited[nx][ny] = true;
                    q.push({{nx, ny}, cnt + 1});
                }
            }
        }
    }

    return -1;
}

int solution(vector<vector<int>> m)
{
    maps = m;
    memset(visited, false, sizeof(visited));
    visited[0][0] = true;
    r = m.size();
    c = m[0].size();
    return BFS(0, 0);
}