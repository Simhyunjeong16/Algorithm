#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int m, x;
    float sum = 0.0;
    vector<int> v;

    cin >> m;

    for(int i = 0; i < m; i++){
        cin >> x;
        v.push_back(x);
    }

    int k = *max_element(v.begin(), v.end());//자기 점수 중, 최댓값

    for(int i = 0; i < m; i++){
        sum += float(v[i]) / k * 100;
    }

    cout << sum / m;
    return 0;
}
