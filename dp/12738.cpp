#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){//12015번. 가장 긴 증가하는 부분 수열2 == same code

    ios::sync_with_stdio(false);
    cin.tie(0);

    int num;
    vector<int> v;
    int x = 0;

    cin >> num;

    for(int i = 0; i < num; i++){
        cin >> x;

        if(i == 0) {
            v.push_back(x);
            continue;
        }

        if(v.back() < x){
            v.push_back(x);
        }
        else{
            auto iter = lower_bound(v.begin(), v.end(), x);
            *iter = x;
        }
    }

    cout << v.size();
    return 0;
}
