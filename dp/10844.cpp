#include <iostream>
#include <string.h>

#define MOD 1000000000

using namespace std;

int n;
int count = 0;
int d[101][10];

//Top Down

int dp(int n, int x){

    if(n == 1){
        if(x == 0) return 0;
        else return 1;
    }
    

    if(d[n][x] != -1)//값이 존재한다는 것은 들어가있다는 것
        return d[n][x];

    if(x == 0)
        return d[n][x] = dp(n-1, x+1) % MOD;

    if(x == 9)
        return d[n][x] = dp(n-1, x-1) % MOD;

    else
        return d[n][x] = (dp(n-1, x-1) + dp(n-1, x+1)) % MOD;
    

}

int main(){
    
    cin >> n;//길이가 몇이니?

    memset(d, -1, sizeof(d));

    for(int i=0; i<=9; i++){ //n:길이, i:맨뒤숫자
        count += dp(n, i);
        count %= MOD;
    }

    cout << count << endl;

    return 0;
}