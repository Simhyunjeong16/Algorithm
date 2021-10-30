#include <iostream>

using namespace std;

int Calc(int x){
    int sum = x;
    
    while(x != 0){
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main(){
    bool a[10001] = {false};

    for(int i = 1; i < 10000; i++){
        int idx = Calc(i);//생성자 찾기

        if(idx <= 10000){
            a[idx] = true;//생성자를 true로
        }
    }

    for(int i = 1; i <= 10000; i++){
        if(!a[i]){//셀프넘버만 출력
            cout << i << "\n";
        }
    }

    return 0;
}