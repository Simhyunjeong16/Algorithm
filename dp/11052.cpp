//카드값의 최댓값 구하기
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int d[10001];
int m[10001];//money


int dp(){
    
    for(int i=1; i<=N; i++){
        cin >> m[i]; //카드팩의 금액을 차례대로 입력
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=i; j++){
            d[i] = max(d[i], d[i-j]+m[j]);
        }
    }

    return d[N];
}

int main(){
    
    cin >> N;

    cout << dp() << endl;

    return 0;

}