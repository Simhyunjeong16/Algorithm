#include <iostream>
#include <queue>

using namespace std;

int main(){
    int a, b, cnt = 0;
    cin >> a >> b;
    
    while(1){
        if(a > b){
            cout << -1;
            break;
        }
        else if(a == b){
            cout << cnt+1;//1을 더한 값을 출력한다
            break;
        }
        
        if(b%10 == 1){//1을 수의 가장 오른쪽에 추가한다.
            b -= 1;
            b /= 10;
        }
        else if(b % 2 == 0){//2를 곱한다.
            b /= 2;
        }
        else{
            cout << -1;
            break;
        }
        cnt++;
    }


    return 0;
}
