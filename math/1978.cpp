#include <iostream>

using namespace std;

int main(){
    
    int n, x, answer = 0;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> x;

        if(x == 1) continue;

        bool flag = true;
        for(int j = 2; j < x; j++){
            if(x % j == 0) {
                flag = false;
                break;
            }
        }
        if(flag) answer++;
    }

    cout << answer;
    return 0;
}