#include <iostream>
#include <vector>
#include <cstring>
#define INF 987654321
using namespace std;
#define MAX 51
int solution(int N, vector<vector<int>> road, int K)
{
    int answer = 0;
    int map[MAX][MAX];

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (i == j)
                map[i][j] = 0;
            else
                map[i][j] = INF;

    for (int i = 0; i < road.size(); i++)
    {
        int p1 = road[i][0];
        int p2 = road[i][1];
        map[p1][p2] = min(map[p1][p2], road[i][2]);
        map[p2][p1] = min(map[p2][p1], road[i][2]);
    }

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);

    for (int i = 1; i <= N; i++)
        if (map[1][i] <= K)
            answer++;

    return answer;
}