#include <string>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

struct pos
{
    bool L, R, U, D;
};

struct pos maps[11][11];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int solution(string dirs)
{
    int answer = 0;
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            maps[i][j].L = false;
            maps[i][j].R = false;
            maps[i][j].U = false;
            maps[i][j].D = false;
        }
    }

    int xpos = 5;
    int ypos = 5;
    for (int i = 0; i < dirs.size(); i++)
    {
        if (dirs[i] == 'L')
        {
            if (xpos <= 0)
                continue;
            if (maps[ypos][xpos].L == false)
            {
                maps[ypos][xpos].L = true;
                maps[ypos][xpos - 1].R = true;
                answer++;
            }
            xpos--;
        }
        else if (dirs[i] == 'R')
        {
            if (xpos >= 10)
                continue;
            if (maps[ypos][xpos].R == false)
            {
                maps[ypos][xpos].R = true;
                maps[ypos][xpos + 1].L = true;
                answer++;
            }
            xpos++;
        }
        else if (dirs[i] == 'U')
        {
            if (ypos >= 10)
                continue;
            if (maps[ypos][xpos].U == false)
            {
                maps[ypos][xpos].U = true;
                maps[ypos + 1][xpos].D = true;
                answer++;
            }
            ypos++;
        }
        else if (dirs[i] == 'D')
        {
            if (ypos <= 0)
                continue;
            if (maps[ypos][xpos].D == false)
            {
                maps[ypos][xpos].D = true;
                maps[ypos - 1][xpos].U = true;
                answer++;
            }
            ypos--;
        }
    }
    return answer;
}