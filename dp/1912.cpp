#include <iostream>
#include <climits>

using namespace std;

int main(){
    int n;
    cin >> n;

    int sum = 0, res = INT_MIN;
    for(int i=0; i<n; i++) {
        int num;
        cin >> num;
        
        sum = max(sum+num, num);//지금까지의 부분 합, 현재 수
        res = max(res, sum);
    }


    cout << res;
    return 0;
}