#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n;
int a[2000001];
int maxi = 2000000;
/*
n이 1000000인 경우, n보다 크거나 같고 소수&팰린드롬 인 수가 필요하다
So, 임의로 난 그 2배를 넣어서 계산
*/
int main(){
    cin >> n;

    //소수 구하기(에라토스테네스 체)
    for(int i = 2; i <= maxi; i++){
        a[i] = i;
    }    

    for(int i = 2; i <= maxi; i++){
        if(a[i] == 0) continue;

        for(int j = i+i; j <= maxi; j += i){
            a[j] = 0;
        }
    }

    //팰린드롬 찾기
    for(int i = n; i <= maxi; i++){
        if(a[i] != 0){
            string x = to_string(a[i]);
            string y = to_string(a[i]);
            reverse(y.begin(), y.end());
            if (x == y){
                cout << x;
                break;
            }
        }
    } 

    return 0;
}
