#include <iostream>

using namespace std;


int d[41];

int dp(int n){

    if(n == 0){
        d[0] = 0;
        return 0;
    }

    else if (n == 1){
        d[1] = 1;
        return 1;
    }
    
    if (d[n] != 0)
        return d[n];
    
    return d[n] = dp(n-1) + dp(n-2); 
    

}

int main(){
    int T;
    cin >> T;//테스트 케이스의 수

    for (int i=0; i<T; i++){
        int N;
        cin >> N;
        
        if(N == 0)
            cout << "1 0" << endl;

        else if(N == 1)
            cout << "0 1" << endl;

        else{
            dp(N);
            cout << d[N-1] << " " << d[N] << endl;
        }
        
    }

    return 0;
}