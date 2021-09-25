#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m, num;
    vector<int> v;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> m;
        v.push_back(m);
    }

    sort(v.begin(), v.end());

    if(n % 2 == 1) num = v[n/2]; //홀수
    else num = v[n/2 -1]; //짝수
    
    cout << num;
    return 0;
}