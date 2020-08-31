#include <iostream>

using namespace std;

int main(){
    int n;
    int answer = -1;
    cin >> n;
    
    int k = n / 5;//5kg 봉지를 사용할 수 있는 최대값
    while(k >= 0){
        
        int x = n - (5 * k);//5kg 봉지를 제외하고 남은 kg

        if (x % 3 == 0) {
            answer = k + (x / 3);
            break;
        }

        k--;
    }

    cout << answer;
    return 0;
}