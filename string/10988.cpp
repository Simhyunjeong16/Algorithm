#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//많은 사람들이 푼 풀이
int main(){
    string s;
    bool chk = true;

    cin >> s;
    
    for(int i = 0; i < s.length()/2; i++){
        if(s[i] != s[s.length()-i-1]) chk = false; //0부터 시작하니까 -1
    }

    if(chk) cout << 1;
    else cout << 0;
    
    return 0;
}

// 내가 푼 풀이
// int main(){
//     string s1, s2;
//     cin >> s1;

//     s2 = s1;//copy string
//     reverse(s1.begin(), s1.end());//펠린드롭

//     if(s1 == s2) cout << 1;
//     else cout << 0;
    
//     return 0;
// }