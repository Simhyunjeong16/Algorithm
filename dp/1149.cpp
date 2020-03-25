#include <iostream>
#include <algorithm>

using namespace std;

int N;
int d[10000001][3];

int dp(){
    int R, G, B;

    for(int i=1; i<=N; i++){
        cin >> R >> G >> B;

        d[i][0] = R + min(d[i-1][1], d[i-1][2]);
        d[i][1] = G + min(d[i-1][0], d[i-1][2]);
        d[i][2] = B + min(d[i-1][0], d[i-1][1]);
    }
    
    int m = min(d[N][0],d[N][1]);
    int result = min(m, d[N][2]); 
    
    return result;
}

int main(){
    
    cin >> N;
    cout << dp() << endl;
    
    return 0;
}