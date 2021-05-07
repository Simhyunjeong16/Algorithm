#include <iostream>
#include <algorithm>

using namespace std;

int t[1000001];
int res = 0;
int n;

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> t[i];
    }

    sort(t, t+n, greater<int>());

    int day = 2;//묘목을 구입하고, 하나를 심는데 걸리는 시간 = 2
    for(int i = 0; i < n; i++){
        res = max(res, day+t[i]);
        day++;
    }
    
    cout << res;
    return 0;
}
