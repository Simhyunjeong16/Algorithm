#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;//n 자기자신
    int x = 1;
    
    while(x < n){
        
        int sum = 0;
        
        for(int i = x; i <= n; i++){
            sum += i;
            if(sum >= n) break;
        }
        
        if(sum == n) answer++;
        x++;
    }
    
    return answer;
}
