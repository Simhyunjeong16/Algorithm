#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){

    int n, m;
    stack<int> s;
    vector<int> v;
    vector<char> r;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> m;
        v.push_back(m);
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++){
        s.push(i);
        r.push_back('+');
        
        while(!s.empty() && s.top() == v[cnt]){
            s.pop();
            r.push_back('-');
            cnt++;
        }

    }
        
        
    if(s.empty()){
        for(char c : r){
            cout << c << "\n";
        }
    }
    else{
        cout << "NO" << "\n";
    }
    
    return 0;
}