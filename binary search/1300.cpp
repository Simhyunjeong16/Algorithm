#include <iostream>

using namespace std;

int main(){
    int n, k;

    cin >> n >> k;

    //이분 탐색
    int start = 1, last = k;
    int ans;

    while(start <= last){
        int cnt = 0;
        int mid = (start + last) / 2;
        
        //같거나 작은 수가 몇개 있는 지 count
        for(int i = 1; i <= n; i++){
            cnt += min(mid / i, n);
        }

        if(cnt < k) {
            start = mid + 1;
        }
        else {
            ans = mid;
            last = mid - 1;
        }
    }

    cout << ans;
    return 0;
}
