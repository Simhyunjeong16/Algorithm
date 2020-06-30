#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

    int n, m, a, f;
    vector<int> v;//상근이가 가지고 잇는 숫자 카드

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d", &f);
        
        int cnt = 0;
        auto it = lower_bound(v.begin(), v.end(), f);

        if(it != v.end()){//존재한다면
            auto it2 = upper_bound(v.begin(), v.end(), f);
            cnt = it2 - it;
        }

        printf("%d ", cnt);
    }


    return 0;
}