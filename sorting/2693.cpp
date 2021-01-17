#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int t;
    int a[10];

    cin >> t;
    
    while(t--){
        
        for(int i = 0; i < 10; i++){
            cin >> a[i];
        }
        sort(a, a+10, greater<int>());

        cout << a[2] << "\n";//3번째 큰 값
    }

    return 0;
}
