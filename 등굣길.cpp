#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX 201

int dp[MAX][MAX];
bool puddle[MAX][MAX];

int solution(int m, int n, vector<vector<int>> puddles)
{
    int answer = 0;

    memset(dp, false, sizeof(dp));
    memset(puddle, false, sizeof(puddle));
    for (int i = 0; i < puddles.size(); i++)
        puddle[puddles[i][1]][puddles[i][0]] = true;

    for (int i = 1; i <= m; i++)
        if (puddle[1][i])
            break;
        else
            dp[1][i] = 1;
    for (int i = 1; i <= n; i++)
        if (puddle[i][1])
            break;
        else
            dp[i][1] = 1;

    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= m; j++)
            if (!puddle[i][j])
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;

    answer = dp[n][m];
    return answer;
}