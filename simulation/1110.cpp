#include <iostream>

using namespace std;

int main(){
    int n, t, tmp = 0;
    int answer = 0;
    cin >> n;

    t = n;

    while(1){
        
        int sum = 0;
        if(t < 10) sum = t;
        else sum = (t / 10) + (t % 10);

        int k = t % 10;

        if(sum < 10) tmp = (k * 10) + sum;
        else tmp = (k * 10) + (sum % 10);
        
        t = tmp;
        answer++;

        if(n == tmp) break;
    }

    cout << answer;
    return 0;
}
