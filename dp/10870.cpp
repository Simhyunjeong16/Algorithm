#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int main(){
    int n;
    cin >> n;

    v.push_back(0);
    v.push_back(1);

    for(int i = 1; i < n; i++){
        v.push_back(v[i-1] + v[i]);
    }

    cout << v[n];
    return 0;
}