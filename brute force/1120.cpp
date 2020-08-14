#include <iostream>
#include <string>

using namespace std;

int main(){
    string a, b;//a의 길이 <= b의 길이
    int answer = 51;

    cin >> a >> b;

    for(int i = 0; i <= b.length() - a.length(); i++){
        int cnt = 0;

        for(int j = 0; j < a.length(); j++){
            if(a[j] != b[i + j]) cnt++;
        }

        if(answer > cnt) answer = cnt;
    }

    cout << answer;
    return 0;
}
