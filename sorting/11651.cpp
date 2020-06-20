#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> x, pair<int, int> y){

    if(x.second == y.second) return x.first < y.first;

    return x.second < y.second; 
}


int main(){

    int n, x, y;
    cin >> n;

    vector<pair<int, int>> v;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }

    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < n; i++){
        cout << v[i].first << " " << v[i].second << "\n";
    }

    return 0;
}