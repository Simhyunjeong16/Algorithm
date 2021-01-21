#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){//quickselect Algorithm = 빠른 선택 알고리즘, 부분적으로 정렬
    vector<int> v;    
    int a, k, x;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> k;

    for(int i = 0; i < a; i++){
        cin >> x;
        v.push_back(x);
    }

    nth_element(v.begin(), v.begin()+(k-1), v.end());//처음, index, 끝
    //k-1번째 자리가 확정날 때까지만 정렬 진행

    // sort(v.begin(), v.end());

    cout << v[k-1];

    return 0;
}
