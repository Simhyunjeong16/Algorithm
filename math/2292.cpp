#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    if(n == 1) {
        cout << 1;
        return 0;
    }

    int sum = 1;//숫자 범위
    for(int i = 1; i <= n; i++){
        sum += 6 * i;

        if(sum >= n){
            cout << i+1;
            break;
        }
    }
    
    return 0;
}
