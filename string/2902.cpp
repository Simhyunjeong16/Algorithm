#include <iostream>
#include <string>

using namespace std;

int main(){
    string str, answer = "";

    cin >> str;

    answer += str[0];
    
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '-'){
            answer += str[i+1];
            i++;
        }
    }

    cout << answer;
    return 0;
}
