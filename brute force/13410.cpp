#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    vector<int> v;
    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= k; i++){
        string str = to_string(n*i);
        reverse(str.begin(), str.end());
        v.push_back(stoi(str));
    }

    sort(v.begin(), v.end(), greater<int>());

    cout << v[0];
    return 0;
}
