#include <iostream>

using namespace std;

int main(){

    int n;
    int a[40001];
    int LIS[40001];
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    int j = 1;
    LIS[j] = a[j];//초기값 설정

    for(int i = 2; i <= n; i++){
        if(LIS[j] < a[i]){//선이 안 꼬일 경우 추가하기
            LIS[++j] = a[i];
        }
        else{
            int t = lower_bound(LIS+1, LIS+1+j, a[i]) - LIS;//LIS+1 = 1부터 시작하니까
            //LIS 뺀 이유 = 위치 찾기
            LIS[t] = a[i];
        }
    }
    
    cout << j;

    return 0;
}
