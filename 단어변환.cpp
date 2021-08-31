#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <queue>
#define MAX 50
#define INF 987654321
using namespace std;
vector<string> word;
int answer;
bool visited[MAX];

bool compare(string s1, string s2)
{
    int diff = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        if (diff > 2)
            return false;
        if (s1[i] != s2[i])
            diff++;
    }
    if (diff == 1)
        return true;
    else
        return false;
}

void BFS(string start, string end)
{
    queue<pair<string, int>> q;
    q.push({start, 0});
    while (!q.empty())
    {
        string curr = q.front().first;
        int count = q.front().second;
        q.pop();
        if (curr == end)
        {
            answer = min(answer, count);
            continue;
        }
        for (int i = 0; i < word.size(); i++)
        {
            if (!visited[i])
            {
                if (compare(curr, word[i]))
                {
                    visited[i] = true;
                    q.push({word[i], count + 1});
                }
            }
        }
    }
}
int solution(string begin, string target, vector<string> words)
{
    bool targetflag = false;
    answer = INF;
    word = words;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < word.size(); i++)
        if (target == word[i])
            targetflag = true;
    if (!targetflag)
        return 0;

    BFS(begin, target);

    return answer;
}