#include <vector>
#include <math.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v;
    
    //3진법으로 변환 및 반전
    while(n > 0){
        v.push_back(n % 3);
        n /= 3;
    }
    
    while(v.front() == 0){
        v.erase(v.begin());
    }
    
    for(int i = 0; i < v.size(); i++){//다시 10진법으로 변환
        answer += v[v.size()-1-i] * pow(3, i);
    }
    
    return answer;
}
