#include <vector>

using namespace std;

long long solution(int n) {//DP
    
    long long d[2001];
    d[1] = 1;//1
    d[2] = 2;//1+1, 2
    
    for(int i = 3; i <= n; i++){
        d[i] = (d[i-1] + d[i-2]) % 1234567;
    }
    
    return d[n];
}