#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000001;
int arr[MAX];
vector<int> v;//소수 vector

void eratosthenes(){//에라토스테네스의 체

    arr[0] = arr[1] = -1;

    for(int i = 2; i < MAX; i++){
        arr[i] = i;
    }

    for(int i = 2; i < MAX; i++){
        if(arr[i] == 0) continue;

        for(int j = i+i; j < MAX; j += i){
            arr[j] = 0;
        }
    }
    
    for(int i = 3; i < MAX; i++){//두 홀수 소수의 합으로 해야하니까 3부터 시작
        if(arr[i] != 0){
            v.push_back(arr[i]);
        }
    }
}


int main(){

    eratosthenes();//미리 최대 값까지 소수 판별해놓기

    int n;
    while(1){
        
        scanf("%d", &n);

        if(n == 0) break;

        int a = 0, b = 0;
        for(int i = 0; i < v.size(); i++){//소수 탐색하며,
            if(arr[n - v[i]] == n - v[i]){//n-v[i]도 소수인 수를 찾는다.
                a = v[i], b = n - v[i];
                printf("%d = %d + %d\n", n, a, b);
                break;
            }
        }

        if(a == 0 && b == 0) printf("Goldbach's conjecture is wrong.\n");
    }
    

    return 0;
}