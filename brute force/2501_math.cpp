#include <iostream>

using namespace std;

int main(){
    int n, k;//n의 약수중 k번째로 작은 수 출력
    int cnt = 0;
    int answer = -1;

    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        if(n % i == 0){//약수 찾기
            cnt++;
            if(cnt == k) {
                answer = i;
                break;
            }
        }

    }

    if(answer == -1) cout << 0;
    else cout << answer;

    return 0;
}
