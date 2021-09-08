#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iostream>
using namespace std;

map<char, int> dic;

int solution(string word)
{
    int answer = 0;
    dic['A'] = 0;
    dic['E'] = 1;
    dic['I'] = 2;
    dic['O'] = 3;
    dic['U'] = 4;

    int p[5] = {1, 5, 25, 125, 625};
    for (int i = 0; i < word.size(); i++)
    {
        answer += 1;
        int index = dic[word[i]];
        for (int j = 0; j < index; j++)
            for (int k = 4; k >= i; k--)
                answer += p[4 - k];
    }
    return answer;
}
