#include <iostream>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    int a[n+1] = {0, };
    for(int i=1; i<=n; i++) cin >> a[i];

    int d[k+1] = {0, };
    for(int i=1; i<=k; i++) d[i] = 10001;//최솟값을 구하는 문제이기 때문에

    for(int i=1; i<=n; i++) {
        for(int j=a[i]; j<=k; j++){
            d[j] = min(d[j], d[j - a[i]] + 1);
        }
    }

    if(d[k] == 10001) d[k] = -1;

    cout << d[k];

    return 0;
}