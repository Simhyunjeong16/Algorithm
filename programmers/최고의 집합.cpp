#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    if(s < n) answer.push_back(-1);//집할 만들 수 없는 경우
    else{
        answer.resize(n);//벡터의 원소의 개수 n개로 지정
        
        int a, c = 0;
        while(n){
            a = s / n;//각 원소의 곱이 최대가 되려면 각 원소의 차이가 최소.
            answer[c] = a;//넣어주기
            s -= a;//넣은 수만큼 빼주기
            n--;
            c++;
        }
    }
    
    return answer;
}
