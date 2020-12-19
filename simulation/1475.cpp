#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int num[10] = {0};
    string s;
    int answer = 0;

    cin >> s;
    
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '6' || s[i] == '9'){
            num[6]++;
            answer = max(answer, num[6]/2 + num[6]%2);
        }
        else{
            num[s[i]-'0']++;
            answer = max(answer, num[s[i]-'0']);
        }
    }
    
    cout << answer;
    return 0;
}
