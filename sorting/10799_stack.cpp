#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){

    stack<char> stick;
    string str;
    int answer = 0;

    cin >> str;

    for(int i = 0; i < str.size(); i++){
        if(str[i] == '(' && str[i+1] == ')'){//레이저
            answer += stick.size();
            i++;
        }
        else{
            if(str[i] == '(') stick.push('(');

            else if(str[i] == ')') {
                stick.pop();
                answer += 1;
            }
        }

    }

    cout << answer;
    return 0;
}
