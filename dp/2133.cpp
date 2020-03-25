#include <iostream>

using namespace std;

int d[1000001];

int dp(int x){

    if(x == 0) return 1;//고유한 모양을 2배씩 곱해줘야할때 사용해야함.
    else if(x == 1) return 0;//홀수는 다 0이다.
    else if(x == 2) return 3;

    if(d[x] != 0) return d[x];

    int result = dp(x-2) * 3;

    for(int i=3; i<=x; i++){
        if (i%2 == 0){//짝수라면? 4 6 8
            result += dp(x-i) * 2;
        }
    }

    return d[x] = result;
}

int main(){
    int N;
    cin >> N;
    
    cout << dp(N) << endl;

    return 0;
}