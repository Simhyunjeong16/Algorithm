#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> dq;
    
    for(string s : operations){
        if(s[0] == 'I') {
            s.erase(0,2);
            dq.push_back(stoi(s));
            sort(dq.begin(), dq.end());
        }
        else{
            if (dq.empty()) continue;
            else if(s == "D 1") dq.pop_back();
            else dq.pop_front();
        }
        
    }
    
    if(dq.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }
    
    return answer;
}