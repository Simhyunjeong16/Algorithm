#include <string>

using namespace std;

string solution(string s) {

    s[0] = toupper(s[0]);

    for(int i = 1; i < s.size(); i++){
        if(s[i] == ' ') continue;
        
        // if(s[i-1] == ' ') s[i] = toupper(s[i]);
        // else s[i] = tolower(s[i]);
        
        s[i-1] == ' ' ? s[i] = toupper(s[i]) : s[i] = tolower(s[i]);
        
    }
    
    return s;
}
