#include <iostream>

using namespace std;

const int MAX = 1000000 + 1;
int d[MAX];
int n = 1;

int dp(int x){  
    
    d[1] = 0;//1을 구하는 건데 d[1]이면 당연히 연산을 안해도 되서 0이다.
    
    for(int i = 2; i <= x; i++){
       
        d[i] = d[i-1] + 1;
        
        if (i%2 == 0)
            d[i] = min(d[i/2] + 1, d[i]);

        if (i%3 == 0)
            d[i] = min(d[i/3] + 1, d[i]);

    }
    return d[x];
    
}


int main(){

    int N;
    cin >> N;

    cout << dp(N) << endl;

    return 0;
}