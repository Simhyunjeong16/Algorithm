#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    string s;
    map<char, int> m;
    char k = 'a';

    cin >> s;

    for(int i = 0; i < 26; i++){
        m.insert({k++, -1});
    }

    for(int i = 0; i < s.length(); i++){
        if(m[s[i]] == -1) m[s[i]] = i;
    }
    
    k = 'a';
    for(int i = 0; i < 26; i++){
        cout << m[k++] << " ";
    }

    return 0;
}
