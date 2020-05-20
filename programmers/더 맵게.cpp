#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    vector<int> v;
    priority_queue< int, vector<int>, greater<int> > pq (scoville.begin(), scoville.end());
    
    
   while(pq.top() < K){
        if(pq.size() == 1) return -1;
        
        int n1 = pq.top();
        pq.pop();

        int n2 = pq.top();
        pq.pop();

        pq.push(n1 + n2*2);
        
        answer++;
    }
    
    
    return answer;
}