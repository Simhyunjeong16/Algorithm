#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main(){
    int n, i;
    vector<string> v;

    cin >> n >> i;

    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        v.push_back(str);
    }

    sort(v.begin(), v.end());

    cout << v[i-1];

    return 0;
}
