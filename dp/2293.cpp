#include <iostream>

using namespace std;

int main(){

    int n, k;
    cin >> n >> k;

    int a[n+1] = {0, };
    int d[k+1] = {0, };

    for(int i=1; i<=n; i++) cin >> a[i];
    

    d[0] = 1;
    for(int i=1; i<=n; i++) {
        for(int j=a[i]; j<=k; j++){
            d[j] += d[j - a[i]];//점화식
        }
    }


    cout << d[k];
    return 0;
}