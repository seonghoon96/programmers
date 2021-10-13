#include <string>
#include <vector>
#include <iostream>
#define MAX 100 + 1
using namespace std;

int block[MAX][MAX];

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<int> answer;
    int num = 1;
    for (int i = 1; i <= rows; i++)
        for (int j = 1; j <= columns; j++)
            block[i][j] = num++;

    for (int q = 0; q < queries.size(); q++)
    {
        int x1, y1, x2, y2;
        x1 = queries[q][0];
        y1 = queries[q][1];
        x2 = queries[q][2];
        y2 = queries[q][3];
        int minimum = block[x1][y1];
        int start = block[x1][y1];
        int x = x1;
        int y = y1;
        for (; x < x2; x++)
        {
            block[x][y] = block[x + 1][y];
            minimum = min(block[x][y], minimum);
        }
        for (; y < y2; y++)
        {
            block[x][y] = block[x][y + 1];
            minimum = min(block[x][y], minimum);
        }
        for (; x > x1; x--)
        {
            block[x][y] = block[x - 1][y];
            minimum = min(block[x][y], minimum);
        }
        for (; y > y1; y--)
        {
            block[x][y] = block[x][y - 1];
            minimum = min(block[x][y], minimum);
        }
        block[x][y + 1] = start;
        minimum = min(minimum, start);
        answer.push_back(minimum);
    }

    return answer;
}