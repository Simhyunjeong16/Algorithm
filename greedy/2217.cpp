#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int w[100001];
int n;

int main(){

    cin >> n;//로프의 숫자
    
    for(int i=0; i<n; i++){
        cin >> w[i]; //각 로프가 버틸 수 있는 최대 중량
    }

    sort(w, w+n);

    int r = 0;
    for(int i=0; i<n; i++){
        r = max(w[i] * (n-i), r);
    }

    cout << r << endl;

    return 0;
}