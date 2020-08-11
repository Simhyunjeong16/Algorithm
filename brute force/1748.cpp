#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;

    int ans = 0;
    int j = 1;
    int num = 10;
    for(int i = 1; i <= n; i++){
        if(i % num == 0){
            j++;
            num *= 10;
        }
        ans += j;
    }
    
    // for(int i = 1; i <= n; i++){
    //     if(i < 10) ans += 1;
    //     else if(i < 100) ans += 2;
    //     else if(i < 1000) ans += 3;
    //     else if(i < 10000) ans += 4;
    //     else if(i < 100000) ans += 5;
    //     else if(i < 1000000) ans += 6;
    //     else if(i < 10000000) ans += 7;
    //     else if(i < 100000000) ans += 8;
    //     else ans += 9;
    // }

    cout << ans;
    return 0;
}