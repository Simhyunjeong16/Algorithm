#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s, t;
    cin >> s >> t;

    while(s.length() < t.length()){// T -> S로 만들기
        
        if(t.back() == 'A'){
            t.pop_back();
        }
        
        else if(t.back() == 'B'){
            t.pop_back();
            reverse(t.begin(), t.end());
        }
    }
    
    if(s == t) cout << 1 << endl;
    else cout << 0 << endl;

    return 0;
}
