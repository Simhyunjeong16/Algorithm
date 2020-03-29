#include <iostream>

using namespace std;

long long int a[91][2];//한자리수, 0과1이라 2
long long int cnt = 0;

int main(){
    int n;
    cin >> n;

    a[1][0] = 0;
    a[1][1] = 1;


    for(int i=2; i<=n; i++){

        a[i][0] = a[i-1][0] + a[i-1][1];
        a[i][1] = a[i-1][0];

    }

    
    cnt = a[n][0] + a[n][1];


    cout << cnt << endl;
    
    return 0;
}