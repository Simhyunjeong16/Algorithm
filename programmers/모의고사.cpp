#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n1[5] = {1,2,3,4,5};
int n2[8] = {2,1,2,3,2,4,2,5};
int n3[10] = {3,3,1,1,2,2,4,4,5,5};
    
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> res(3);
    
    for(int i = 0; i < answers.size(); i++){
        if(answers[i] == n1[i % 5]) res[0]++;
        if(answers[i] == n2[i % 8]) res[1]++;
        if(answers[i] == n3[i % 10]) res[2]++;
    }
    
    int maxnum = *max_element(res.begin(), res.end());//max값 구하기
    
    for(int i = 0; i < 3; i++){
        if(res[i] == maxnum) answer.push_back(i+1);
    }
    
    return answer;
}