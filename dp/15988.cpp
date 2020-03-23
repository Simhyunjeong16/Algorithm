#include <iostream>

using namespace std;

long long int d[1000001];

long long int dp(int x){


   if (x == 1) return 1;
   else if (x == 2) return 2;
   else if (x == 3) return 4;

   if (d[x] != 0) return d[x];

   return d[x] = (dp(x-1) + dp(x-2) + dp(x-3)) % 1000000009;
}


int main(){
    int T;
    cin >> T;//테스트 케이스 개수

    int n;
    for(int i=0; i<T; i++){
        cin >> n;
        cout << dp(n) << endl;
    }

    return 0;
}