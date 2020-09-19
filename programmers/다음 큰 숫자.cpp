#include <string>
#include <vector>

using namespace std;

int Calc(int n){
    int cnt = 1;
    
    while(n > 0){
        if(n % 2 == 1) cnt++;
        n /= 2;
    }
    
    return cnt;
}

int solution(int n) {
    int answer = 0;
    int n_size = Calc(n);
    
    while(1){
        n++;
        if(n_size == Calc(n)){
            answer = n;
            break;
        }
    }
    
    return answer;
}
