#include <iostream>

using namespace std;

int main(){
    int n, k, p;
    int a[1001];
    int cnt = 0;

    cin >> n >> k;

    for(int i = 2; i <= n; i++){
        a[i] = i;
    }

    for(int i = 2; i <= n; i++){
        if(a[i] == 0) continue;
        
        for(int j = i; j <= n; j += i){//j는 소수
            if(a[j] == 0) continue;
            a[j] = 0;
            cnt++;

            if(cnt == k){
                cout << j;
                return 0;
            }
        }
    }
}
