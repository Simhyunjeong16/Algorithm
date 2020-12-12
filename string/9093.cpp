#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string str;
    int n;

    cin >> n;
    
    // 남은'\n'를 지워주기 위해
    // string remainder;
    // getline(cin, remainder);
    cin.ignore();//버퍼 비우기

    for(int i = 0; i < n; i++){
        getline(cin, str);

        string t = "";
        for(int i = 0; i < str.length(); i++){

            if(str[i] == ' ') {
                reverse(t.begin(), t.end());//뒤집기
                cout << t << " ";
                t = "";//초기화
            }
            else {
                t += str[i];
            }
        }

        reverse(t.begin(), t.end());//뒤집기
        cout << t << "\n";
    }

    return 0;
}
