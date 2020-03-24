#include <iostream>

using namespace std;

//오버플로우가 발생할 수 있기 때문에 long long을 써줘야 한다.

long long int d[10000001][2];//2차원 다이나믹 프로그래밍

long long int dp(int x){

    d[0][0] = 0;
    d[1][0] = 2;
    d[2][0] = 7;
    d[2][1] = 1;

    for(int i=3; i<=x; i++){
        d[i][1] = (d[i-1][1] + d[i-3][0]) % 1000000007;
        d[i][0] = (d[i-2][0]*3 + d[i-1][0]*2 + d[i][1]*2) % 1000000007;
    }

    return d[x][0];
}

int main(){
    int N;
    cin >> N;
    
    cout << dp(N) << endl;

    return 0;
}