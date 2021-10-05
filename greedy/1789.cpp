#include <iostream>

using namespace std;

int main(){
    long long s;
    cin >> s;

    int num = 1;
    int cnt = 0;
    long long sum = 0;
    
    while(1){
        sum += num;
        cnt++;
        if(sum > s){
            cout << cnt-1;
            break;
        }
        num++;
    }

    return 0;
}