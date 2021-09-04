#include <string>
#include <vector>

using namespace std;
#define MAX 1000000

int dp[MAX][2];
int solution(vector<int> money)
{
    int answer = 0;
    dp[0][0] = money[0];
    dp[1][0] = money[0];
    dp[0][1] = 0;
    dp[1][1] = money[1];
    for (int i = 2; i < money.size(); i++)
    {
        dp[i][0] = max(dp[i - 2][0] + money[i], dp[i - 1][0]);
        dp[i][1] = max(dp[i - 2][1] + money[i], dp[i - 1][1]);
    }
    answer = max(dp[money.size() - 2][0], dp[money.size() - 1][1]);
    return answer;
}