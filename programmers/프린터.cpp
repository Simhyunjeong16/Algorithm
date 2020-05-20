#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;
    priority_queue<int> pq;//우선 순위 큐
    
    for(int i = 0; i < priorities.size(); i++){
        q.push(make_pair(priorities[i], i));
        pq.push(priorities[i]);
    }
    
    
    while(!q.empty()){
        
        int prior = q.front().first;
        int pos = q.front().second;
        q.pop();
        
        if(pq.top() == prior){
            pq.pop();
            answer++;
            
            if(location == pos) break;
        }
        else{
            q.push(make_pair(prior, pos));
        }
        
    }
    
    
    
    return answer;
}