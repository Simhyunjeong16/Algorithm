#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> weight) {
    int answer = 0;
    
    sort(weight.begin(), weight.end());//1, 1, 2, 3, 6, 7, 30
    
    answer += weight[0];
    for(int i = 1; i < weight.size(); i++){
        //만약 지금까지 더한 수 보다 더 큰 수가 나온다면 answer가 만들수 없는 수이다
        if(answer+1 < weight[i]) break;
        
        answer += weight[i];
    }
    return answer+1;
}