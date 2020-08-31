#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int, vector<int>, less<int>> pq;
    queue<pair<int, int>> q;
    
    for(int i = 0; i < priorities.size(); i++){
        q.push(make_pair(priorities[i], i));   
        pq.push(priorities[i]);
    }
    
    while(1){
        
        if(q.front().first == pq.top()){//가장 우선순위가 높은게 앞에 있다면
            answer++;
            if(location == q.front().second) break;
            q.pop();
            pq.pop();
        }
        else{
            q.push(q.front());
            q.pop();
        }
    }
    
    return answer;
}