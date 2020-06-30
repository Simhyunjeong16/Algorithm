#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        string str;
        cin >> str;

        stack<char> s;
        for(int j = 0; j < str.size(); j++){

            if(s.empty()){
                s.push(str[j]);
            }
            else if(s.top() == '(' && str[j] == ')'){
                s.pop();
            } 
            else{//str[j] == '('
                s.push(str[j]);
            }
        }

        cout << (s.empty() ? "YES" : "NO") << "\n";
    }
    
    return 0;
}