#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes)
{
    int answer = 0;
    for (int i = 0; i < sizes.size(); i++)
    {
        if (sizes[i][0] > sizes[i][1])
            continue;
        int tmp = sizes[i][0];
        sizes[i][0] = sizes[i][1];
        sizes[i][1] = tmp;
    }
    int width = 0;
    int height = 0;
    for (int i = 0; i < sizes.size(); i++)
    {
        width = max(width, sizes[i][0]);
        height = max(height, sizes[i][1]);
    }

    answer = width * height;
    return answer;
}