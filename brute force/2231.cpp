#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    
    int result;
    bool flag = false;
    
    for(int i=1; i<N; i++){//젤 작은 수 부터 시작

        int copy = i;
        int sum = i;

        //각 자리의 숫자 더하기
         while(copy != 0){
            sum += (copy % 10);
            copy /= 10;
        }
        
        if(N == sum) {
            result = i;
            flag = true;
            break;
        }
    }

    if(!flag) result = 0;
    
    cout << result;
    return 0;
}