#include <vector>
#include <iostream>

using namespace std;

int solution(int N) {
    
    vector<int> v;
    
    //2진법으로 변환
    while(N > 1){
        v.push_back(N % 2);
        N /= 2;
    }
    v.push_back(1);
    
    int cnt = 0, answer = 0;
    bool flag = false;
    
    for(size_t i = 0; i < v.size(); i++){
        if(!flag && v[i] == 1){
            flag = true;
            cnt = 0;
        }
        else if(flag && v[i] == 1){
            if(answer < cnt) answer = cnt;
            cnt = 0;
        }
        else if(flag && v[i] == 0){
            cnt++;
        }
    }
    
    
    return answer;
}
