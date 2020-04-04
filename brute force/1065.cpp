#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    int result = 0;

    if(n < 100){
        result = n;
    }

    else{
        result = 99;

        for(int i=100; i<=n; i++){
            int a = i/100;
            int b = (i%100)/10;
            int c = (i%100)%10;

            if((a-b) == (b-c)) result++;
        }
    }

    cout << result;
    return 0;
}