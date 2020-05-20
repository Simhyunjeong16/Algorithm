#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int day = 0, maxday = 0;
    for(int i = 0; i < progresses.size(); i++){
        
        day = (100 - progresses[i]) / speeds[i];
        if((100 - progresses[i]) % speeds[i] != 0) day++;
        
        
        if(answer.empty() || maxday < day)
            answer.push_back(1);
        else 
            ++answer.back();
        
        
        maxday = max(maxday, day);
        
    }
    
    return answer;
}