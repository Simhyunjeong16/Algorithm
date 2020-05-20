#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> a;
    
    for(int i = 0; i < progresses.size(); i++){
        int n = (100 - progresses[i]) / speeds[i];
        if((100 - progresses[i]) % speeds[i] != 0) n++;
        
        a.push_back(n);
    }
    
    int day = a[0];
    int cnt = 1;
    for(int i = 1; i < a.size(); i++){
        if(day >= a[i]) cnt++;
        else{
            answer.push_back(cnt);
            cnt = 1;
            day = a[i];
        }
    }
    answer.push_back(cnt);
    
    return answer;
}