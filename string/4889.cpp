#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    string str;
    int num = 1;
    
    while(1){
        cin >> str;

        if(str[0] == '-') break;
        
        stack<char> st;
        int answer = 0;

        for(int i = 0; i < str.size(); i++){
            if(str[i] == '}' && !st.empty() && st.top() == '{'){
                st.pop();
            }
            else{
                st.push(str[i]);
            }
        }

        while(!st.empty()){
            char a = st.top();
            st.pop();
            char b = st.top();
            st.pop();
            
            if(a == b) answer += 1;
            else answer += 2;
        }
        
        cout << num++ << ". " << answer << '\n';
    }

    return 0;
}
