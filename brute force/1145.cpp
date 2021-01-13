#include <iostream>

using namespace std;

int main(){

    int a[5];
    
    for(int i = 0; i < 5; i++){
        cin >> a[i];
    }

    for(int i = 1;; i++){//조건식을 생략하면 계속해서 반복!

        int chk = 0;
        for(int j = 0; j < 5; j++){
            if(i % a[j] == 0) chk++;//나누어 떨어지는 수라면 chk++
        }

        if(chk >= 3){//적어도 세 개로 나누어 지는 가장 작은 자연수
            cout << i;
            break;
        }
    }

    return 0;
}
