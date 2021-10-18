#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

typedef struct
{
    string full;
    string head;
    int num;
} Name;

vector<Name> f;

bool compare(Name n1, Name n2)
{
    if (n1.head != n2.head)
        return n1.head < n2.head;
    else
        return n1.num < n2.num;
}

vector<string> solution(vector<string> file)
{
    vector<string> answer;

    for (int k = 0; k < file.size(); k++)
    {
        Name name;
        name.full = file[k];
        string s = "";
        int i = 0;
        while (!isdigit(file[k][i]))
            i++;
        name.head = file[k].substr(0, i);
        std::transform(name.head.begin(), name.head.end(), name.head.begin(), ::tolower);
        int tmp = i;
        while (isdigit(file[k][i]))
        {
            i++;
            if (i - tmp >= 5)
                break;
        }
        name.num = stoi(file[k].substr(tmp, i - tmp));
        f.push_back(name);
    }

    stable_sort(f.begin(), f.end(), compare);

    for (int i = 0; i < f.size(); i++)
        answer.push_back(f[i].full);

    return answer;
}