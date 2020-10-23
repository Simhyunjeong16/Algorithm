#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    //시간 단축(입출력 속도 높이기)
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, x;
    int a[100001];

    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a+n);

    cin >> m;

    for(int i = 0; i < m; i++){//이 수들이 a배열 안에 존재하는지 알아내기
        cin >> x;

        auto it = lower_bound(a, a+n, x);

        if(*it == x) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
    
    
    return 0;
}
