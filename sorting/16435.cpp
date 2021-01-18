#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n, l, x;
    vector<int> v;

    cin >> n >> l;//과일의 개수, 스네이크버드의 초기 길이 정수

    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());

    for(int i = 0; i < n; i++){
        if(v[i] <= l){
            l++;//과일을 먹었다!
        }
    }

    cout << l;

    return 0;
}
