#include <iostream>

using namespace std;

int d[1000001];

int dp(int n){
    
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;

    for (int i = 4; i <= n; i++){
        d[i] = d[i-1] + d[i-2] + d[i-3];
    }

    return d[n];
}

int main(){
    int T;
    cin >> T;

    for (int i = 0; i < T; i++){
        int n;
        cin >> n;
        cout << dp(n) << endl;
    }

    return 0;
}