#include <iostream>

using namespace std;

int n;
int a[15];
int ans = 0;

bool chk(int lev){
    for(int i = 0; i < lev; i++){
        if(a[i] == a[lev]) return false;//같은 행인지 아닌지 판단
        if(abs(a[lev]-a[i]) == lev-i) return false;//대각선 판단
    }
    return true;
}

void n_queen(int x){

    if(x == n) {
        ans++;
    }
    else{
        for(int i = 0; i < n; i++){
            a[x] = i;
            if(chk(x)) n_queen(x+1);
        }
    }

}


int main(){ //퀸의 특성: 체스판 1 행당 1개의 퀸만 존재할 수 있다.
    cin >> n;
    n_queen(0);

    cout << ans;
    return 0;
}
