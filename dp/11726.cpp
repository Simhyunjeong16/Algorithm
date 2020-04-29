#include <iostream>

using namespace std;

int d[1001];
int dp(int x){

    if(x == 1)  {
        d[x] = 1;
        return 1;
    }
    else if(x == 2){
        d[x] = 2;
        return 2;
    } 

    if (d[x] != 0) return d[x];

    return d[x] = (dp(x-1) + dp(x-2)) % 10007;

}

int main(){
    int n;
    cin >> n;
    
    cout << dp(n) << endl;

    return 0;
}