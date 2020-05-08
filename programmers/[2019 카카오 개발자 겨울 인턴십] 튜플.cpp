#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    s = s.substr(1,s.size()-2);//앞뒤{}를 제거
    
    vector<int> v;//각각 더한 vector
    string str = "";
    int num = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '{') continue;
        else if(s[i] == '}'){
            num += stoi(str);
            v.push_back(num);
            str = "";
            num = 0;
            s.erase(i+1,1);//i+1위치에 있는 ,지우기
        }
        else if(s[i] == ',') {
            num += stoi(str);
            str = "";
        }
        else str += s[i];
    }
    
    sort(v.begin(), v.end());
    
    answer.push_back(v[0]);
    for(int i=1; i<v.size(); i++){
        answer.push_back(v[i]-v[i-1]);
    }
    
    
    return answer;
}