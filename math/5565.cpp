#include <iostream>

using namespace std;

int main(){
    int total, x;
    cin >> total;

    for(int i = 0; i < 9; i++){
        cin >> x;
        total -= x;
    }

    cout << total;
    return 0;
}
