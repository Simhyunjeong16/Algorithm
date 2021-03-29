#include <iostream>
using namespace std;

int main(){

    int a[11];
    int result = 100;
    
    for(int i = 0; i < 10; i++){
        cin >> a[i];
    }

    for(int i = 0; i < 9; i++){
        int sum = a[i];
        if(abs(result) > abs(100-sum)) result = 100-sum;
        else if(abs(result) == abs(100-sum)) result = min(result, 100-sum);
        else continue;

        for(int j = i+1; j < 10; j++){
            sum += a[j];            
            if(abs(result) > abs(100-sum)) result = 100-sum;
            else if(abs(result) == abs(100-sum)) result = min(result, 100-sum);
            else break;
        }
    }

    cout << 100 - result;
    return 0;
}
