#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> triangle)
{
    int answer = 0;
    int size = triangle.size();
    vector<vector<int>> dp(size, vector<int>(size));

    dp[0][0] = triangle[0][0];
    for (int i = 0; i < triangle.size() - 1; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            dp[i + 1][j] = max(dp[i][j] + triangle[i + 1][j], dp[i + 1][j]);
            dp[i + 1][j + 1] = max(dp[i][j] + triangle[i + 1][j + 1], dp[i + 1][j + 1]);
        }
    }

    for (int i = 0; i < size; i++)
        answer = max(answer, dp[size - 1][i]);

    return answer;
}