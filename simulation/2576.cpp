#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int a[7];
    int sum = 0, mini = 1e9;

    for(int i = 0; i < 7; i++){
        cin >> a[i];
        
        if(a[i] % 2 == 1) {
            sum += a[i];
            mini = min(mini, a[i]);
        }
    }

    if(sum == 0){
        cout << -1;
    }
    else {
        cout << sum << "\n" << mini;
    }

    return 0;
}