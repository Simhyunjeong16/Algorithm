#include <iostream>

using namespace std;

//방법2
int factorial(int n){
    if(n <= 1) return 1;
    return n * factorial(n-1);
}

int main(){
    int n;
    int answer = 1;
    cin >> n;

    // if(n == 0){
    //     cout << 1;
    //     return 0;
    // }
    // else if(n < 3){
    //     cout << n;
    //     return 0;
    // }
    // for(int i = 2; i <= n; i++){
    //     answer *= i;
    // }
 
    // cout << answer;

    cout << factorial(n);  
    return 0;
}
