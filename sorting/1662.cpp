#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){

    stack<string> st;
    string s;
    int ans = 0;

    cin >> s;

    for(int i = 0; i < s.size(); i++){

        if(s[i] == '('){
            st.push("(");
        }
        else if(i < s.size()-1 && s[i+1] == '('){
            string n = "";
            n += s[i];
            st.push(n);
        }
        else if(s[i] == ')'){

            int sum = 0;
            while(1){
                if(st.top() == "(") {
                    st.pop();
                    break;
                }
                sum += stoi(st.top());
                st.pop();
            }

            int n = stoi(st.top());//n번 반복합니다.
            st.pop();
            st.push(to_string(n * sum));
        }
        else{//문자열 길이만 저장
            st.push("1");//s[i]가 한글자니까
        }
    }
    
    while(!st.empty()){
        // cout << st.top() << endl;
        ans += stoi(st.top());
        st.pop();    
    }

    cout << ans;
    
    return 0;
}