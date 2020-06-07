#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp{
    bool operator()(pair<int,int> x, pair<int,int> y){
        return x.second > y.second;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(), jobs.end());//들어온 시간에 따른 정렬
    priority_queue<pair<int,int>,vector<pair<int,int>>, cmp> pq;//min heap
    
    int time = 0;//시간
    int i = 0;//index
    while(i < jobs.size() || !pq.empty()){
        
        if(i < jobs.size() && jobs[i][0] <= time){
            pq.push(make_pair(jobs[i][0], jobs[i][1]));
            i++;
            continue;
        }
        
        if(!pq.empty()){
            time += pq.top().second;//작업이 끝날 때까지 걸린 시간
            answer +=  time - pq.top().first;//총 걸린시간 - 들어온 시간
            pq.pop();
        }
        else{
            time = jobs[i][0];//다음 작업 시간으로 넘기기
        }
    }
    

    return answer / jobs.size();
}