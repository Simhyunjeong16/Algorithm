#include <iostream>
#include <string.h>

using namespace std;

int n;
int d[1001][11];
int cnt = 0;

//bottom up

int main(){

    cin >> n;//수의 길이

    for(int i=0; i<10; i++)
        d[1][i] = 1;

    
    for(int i=2; i<=n; i++){
        for(int j=0; j<10; j++){
            
            if (j == 0){
                d[i][j] = d[i-1][j] % 10007;//자기자신
            }

            else{
                d[i][j] = (d[i-1][j] + d[i][j-1])% 10007;//자기자신 + 그전배열
            }

        }
    }



    for(int i=0; i<10; i++)
        cnt = (cnt + d[n][i]) % 10007;//n: 수의 길이, i: 오르막 수 맨앞
 

    cout << cnt << endl;

    return 0;
}