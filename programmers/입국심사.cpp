#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long human = 0;//인원수
    long long avgTime;
    long long minTime = 1;//최소시간
    long long maxTime = *max_element(times.begin(), times.end()) * (long long)n;//가장 느린 심사관이 모든 사람들을 한명씩 심사하는 경우
    
    answer = maxTime;
    
    while(minTime <= maxTime){
        avgTime = (minTime + maxTime) / 2;
        
        for(int t : times){//현재 시간으로 돌릴수 있는 최대 인원 구하기
            human += avgTime / t;
        }
        
        if(n <= human) {//최대 인원이 총 인원보다 크거나 같다면
            if(avgTime < answer) answer = avgTime;
            maxTime = avgTime - 1;//최대시간 갱신
        }
        else if (n > human) minTime = avgTime + 1;//총 인원보다 적다면 현재시간보다 커야하므로 최소시간 갱신
        
        human = 0;//인원수 초기화
    }
    
    
    return answer;
}