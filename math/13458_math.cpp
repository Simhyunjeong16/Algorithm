#include <iostream>

using namespace std;

int n;//시험장
int a[1000000];//응시자
int b, c;//총감독관 감시 가능 인원, 부감독관 감시 가능 인원

int main(){

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> b >> c;

    int ans = n;
    for(int i = 0; i < n; i++){
         a[i] -= b;

        if(a[i] > 0){
            ans += (a[i]/c);
            if(a[i]%c > 0) ans++;
        }
    }

    cout << ans;
    return 0;
}
