#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    
    sort(routes.begin(), routes.end());//차량들의 고속도로 진입 지점 기준으로 sort
    
    int tmp = routes[0][1];//첫번째 차량 진출 지점
    for(int i = 1; i < routes.size(); i++){
        
        if(tmp > routes[i][1]){//최근에 설치한 카메라 > i번째 차량 진출 지점
            tmp = routes[i][1];
        }
        if(tmp < routes[i][0]){//최근에 설치한 카메라 < i번째 차량 진입 지점
            answer++;//새로운 카메라 설치
            tmp = routes[i][1];
        }    
    }
    
    return answer;
}