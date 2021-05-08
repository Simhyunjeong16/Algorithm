#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, l, x;
    vector<int> v;

    cin >> n >> l;
    
    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());

    int answer = 1;
    int left = v[0];
    for(int i = 1; i < v.size(); i++){
        if(v[i] - left + 1 > l){//좌우로 0.5씩 간격
            answer++;
            left = v[i];
        }
    }

    cout << answer;

    return 0;
}