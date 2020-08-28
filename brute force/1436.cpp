#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;

    int k = 665;
    int cnt = 0;
    string s = "";

    while(k++){
        s = to_string(k);

        if(s.find("666") != string::npos) cnt++;//해당 문자열을 찾았다.
        
        if(cnt == n){
            cout << s;
            break;
        }
    }

    return 0;
}