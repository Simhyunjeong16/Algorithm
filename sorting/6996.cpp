#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    int t;
    string a, b;
    cin >> t;
    
    while(t--){
        cin >> a >> b;

        map<char, int> m;
        
        for(int i = 0; i < a.length(); i++){
            m[a[i]]++;
        }

        for(int i = 0; i < b.length(); i++){
            m[b[i]]--;
        }
        
        int k;
        for(k = 0; k < m.size(); k++){
            if(m[k] != 0){
                cout << a << " & " << b << " are NOT anagrams.\n";
                break;
            }
        }

        if(k == m.size()) cout << a << " & " << b << " are anagrams.\n";
    }
    return 0;
}
