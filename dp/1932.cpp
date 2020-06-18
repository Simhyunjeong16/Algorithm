#include <iostream>

using namespace std;

int d[500][500];

int main(){

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cin >> d[i][j];
        }
    }

    for(int i = 1; i < n; i++){
        for(int j = 0; j <= i; j++){
            d[i][j] += max(d[i-1][j], d[i-1][j-1]);//아래에서 위로 가니까 i-1, j vs j-1
        }
    }

    int answer = 0;
    for(int i=0; i<n; i++){
        if(answer < d[n-1][i]){
            answer = d[n-1][i];
        }
    }

    // 값 제대로 나오나 print
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j <= i; j++){
    //         cout << d[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << answer;
    return 0;
}