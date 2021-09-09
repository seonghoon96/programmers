#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <cstring>
#include <iostream>
using namespace std;

typedef struct
{
    string name;
    vector<pair<string, int>> score;
} Job;
vector<Job> v;

vector<Job> splitToken(vector<string> table)
{
    vector<Job> vec;
    for (int i = 0; i < table.size(); i++)
    {
        Job job;
        stringstream s;
        s.str(table[i]);
        string token;
        s >> token;
        job.name = token;
        int score = 5;
        while (s >> token)
            job.score.push_back({token, score--});
        vec.push_back(job);
    }
    return vec;
}

string solution(vector<string> table, vector<string> languages, vector<int> preference)
{
    string answer = "";
    v = splitToken(table);
    vector<int> result(5, 0);
    for (int i = 0; i < 5; i++)
    {
        Job job = v[i];
        for (int j = 0; j < languages.size(); j++)
        {
            for (int k = 0; k < 5; k++)
            {
                if (v[i].score[k].first == languages[j])
                {
                    result[i] += v[i].score[k].second * preference[j];
                    break;
                }
            }
        }
    }
    int maxindex = 0;
    int maximum = result[0];
    for (int i = 1; i < 5; i++)
    {
        if (result[i] > maximum)
        {
            maxindex = i;
            maximum = result[i];
        }
        else if (result[i] == maximum)
        {
            if (v[i].name < v[maxindex].name)
            {
                maxindex = i;
                maximum = result[i];
            }
        }
    }
    answer = v[maxindex].name;
    return answer;
}