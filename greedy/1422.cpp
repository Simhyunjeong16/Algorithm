#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool cmp(string x, string y){
    if(x + y > y + x) return true;
    return false;
}


int main(){

    vector<string> v;
    string x;
    string t = "";
    int k, n;
    
    cin >> k >> n;

    for(int i = 0; i < k; i++){
        cin >> x;
        v.push_back(x);

        if((t.length() < x.length()) || (t.length() == x.length() && t < x)){
            t = x;//제일 긴수 중 큰 수를 넣어야 값이 커진다
        }
    }
    
    for(int i = 0; i < n-k; i++){
        v.push_back(t);
    }

    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < n; i++) {
        cout << v[i];
    }
    
    return 0;
}
