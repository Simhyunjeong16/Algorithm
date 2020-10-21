#include <iostream>

using namespace std;

int main(){
    int n, m;
    int a[10001];

    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int i = 0, j = 0;
    int sum = 0, cnt = 0;
    
    while(j < n){

        if(sum < m){
            sum += a[i];
            i++;
        }
        else if(sum >= m) {
            if(sum == m) cnt++;
            sum -= a[j];
            j++;
        }       
        
    }

    cout << cnt;
    
    return 0;
}