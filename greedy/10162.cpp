#include <iostream>

using namespace std;

int main(){
    
    int t;//초 단위
    int a = 0, b = 0, c = 0;//A 5분(300초), B는 1분(60초), C는 10초
    
    cin >> t;

    if(t % 10 == 0){

        while(t >= 300){
            t -= 300;
            a += 1;
        }
        while(t >= 60){
            t -= 60;
            b += 1;
        }

        while(t >= 10){
            t -= 10;
            c += 1;
        }
        cout << a << " " << b << " " << c;
    }
    else{
        cout << -1;
    }

    return 0;
}