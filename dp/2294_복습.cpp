//ebay-korea 비슷문제

#include <iostream>
using namespace std;

int main(){

    int a[101] = {0, };//종류 arr
    int d[10001] = {0, };//가격 arr
    int n, k;
    
    cin >> n >> k;//n가지 종류, k원

    for(int i = 1; i <= n; i++){//n종류 만큼 받기
        cin >> a[i];
    }

    for(int i = 1; i <= k; i++){//k원까지 가격 최댓값으로 설정하기
        d[i] = 10001;
    }

    for(int i = 1; i <= n; i++){
        for(int j = a[i]; j <= k; j++){
            d[j] = min(d[j], d[j - a[i]] + 1);//점화식
        }
    }

    if(d[k] == 10001) cout << -1;
    else cout << d[k];
    
    return 0;
}
