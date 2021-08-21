#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 5
bool visited[MAX][MAX];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int bfs(vector<string> v, int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx and nx < 5 and 0 <= ny and ny < 5 and !visited[nx][ny])
        {
            visited[nx][ny] = true;
            if (v[nx][ny] == 'O')
            {
                q.push({nx, ny});
                for (int j = 0; j < 4; j++)
                {
                    int nnx = nx + dx[j];
                    int nny = ny + dy[j];
                    if (0 <= nnx and nnx < 5 and 0 <= nny and nny < 5 and !visited[nnx][nny])
                    {
                        visited[nx][ny] = true;
                        if (v[nnx][nny] == 'P')
                            return -1;
                    }
                }
            }
            else if (v[nx][ny] == 'P')
                return -1;
        }
    }

    return 1;
}

int checkSpace(vector<string> v)
{
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
        {
            if (v[i][j] == 'P')
            {
                memset(visited, false, sizeof(visited));
                if (bfs(v, i, j) == -1)
                    return 0;
            }
        }
    return 1;
}

vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;

    for (int i = 0; i < 5; i++)
    {
        if (checkSpace(places[i]))
            answer.push_back(1);
        else
            answer.push_back(0);
    }

    return answer;
}