#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main(){
    int n, m, sum, num, res = INT_MAX;
    vector<int> v;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> m;
        v.push_back(m);
    }

    sort(v.begin(), v.end());

    for(int i = v.front(); i <= v.back(); i++){
        sum = 0;
        
        for(int j = 0; j < v.size(); j++){
            sum += abs(v[j]-i);
        }

        if(res > sum){
            res = sum;
            num = i;
        }
        else if(res == sum && num > i){
            num = i;
        }
    }

    cout << num;
    return 0;
}