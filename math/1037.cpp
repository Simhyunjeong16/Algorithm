#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n, x;
    vector<int> v;
    cin >> n;

    for(int i=0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }

    int max = *max_element(v.begin(), v.end());
    int min = *min_element(v.begin(), v.end());

    cout << max*min;
    return 0;
}