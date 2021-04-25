#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    string str;

    while(getline(cin, str)){
        if(str == ".") break;

        stack<char> st;
        bool flag = true;

        for(char it : str){
    
            if(it == '(' || it == '[') st.push(it);
    
            else if(it == ')'){
                if(!st.empty() && st.top() == '(') st.pop();
                else {
                    flag = false;
                    cout << "no" << "\n";
                    break;    
                }
            }
    
            else if(it == ']'){
                if(!st.empty() && st.top() == '[') st.pop();
                else {
                    flag = false;
                    cout << "no" << "\n";
                    break;    
                }
            }
        }

        if(!flag) continue;
        cout << (st.empty() ? "yes" : "no") << "\n";
    }

    return 0;
}
