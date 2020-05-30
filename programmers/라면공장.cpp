#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    priority_queue<int> pq;
    
    int i = 0;
    for(int day = 0; day < k; day++){
        
        if(day == dates[i]){//공급 날짜
            pq.push(supplies[i]);
            
            if(i != dates.size()-1) i++;
        }
            
        if(stock == 0){//잔여 밀가루가 없다면
            answer++;
            stock += pq.top();
            pq.pop();
        }

        stock--;//밀가루 소비
        
    }

    return answer;
}