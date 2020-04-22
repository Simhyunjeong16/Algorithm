#include <iostream>
#include <algorithm>

using namespace std;

int a[1001];
int d[1001];//증가용
int d2[1001];//감소용

int num;
int result = 0;

int main(){
    
    cin >> num; //수열의 크기

    for(int i=0; i<num; i++){
        cin >> a[i];
    }


    //가장 긴 증가하는 부분 수열
    for(int i=0; i<num; i++){
        d[i] = 1;

        for(int j=0; j<i; j++){
            if(a[j] < a[i] && d[i] < d[j]+1){
                d[i] = d[j]+1;
               
            }
        }
    }

    
    //가장 긴 감소하는 부분 수열
    for(int i=num-1; i>=0; i--){
        d2[i] = 1;

        for(int j=num-1; j>=i; j--){
            if(a[j] < a[i] && d2[i] < d2[j]+1){//바꿔주기
                d2[i] = d2[j]+1;
            }
        }
    }
    

    //최댓값 찾기
    for(int i=0; i<num; i++){
        result = max(result, d[i] + d2[i] -1);//중복된 값 하나 빼기
    }
    cout << result;


    return 0;
}