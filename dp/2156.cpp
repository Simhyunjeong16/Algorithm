//2579번 계단오르기 문제와 유사

#include <iostream>

using namespace std;

int d[10001] = {0,};
int a[10001] = {0,};
int main(){
    int n;
    cin >> n;//포도잔의 개수

    for(int i=1; i<=n; i++){
        cin >> a[i];
    }

    d[1] = a[1];
    d[2] = a[1] + a[2];

    for(int i=3; i<=n; i++){
        d[i] = max(d[i-2] + a[i], d[i-3] + a[i-1] + a[i]);
        // d[i] = d[i-2] + a[i]; //현재 포도주를 마시고 이전꺼를 안먹었을 경우
        // d[i] = d[i-3] + a[i-1] + a[i]; //현재 포도주와 이전의 포도주를 마신 경우
        d[i] = max(d[i], d[i-1]);//d[i-1] : 내가 현재 포도주를 먹지 않았을 경우
    }


    cout << d[n];
    return 0;

}