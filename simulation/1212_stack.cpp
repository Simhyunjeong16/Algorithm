#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    string n;
    stack<int> st;

    cin >> n;
    
    if(n == "0") {
        cout << 0;
        return 0;
    }

    //8진수 -> 2진수
    for(int i = n.size()-1; i >= 0; i--){
        int x = n[i] - '0';

        for(int j = 0; j < 3; j++){//8진수에서 2진수로 변환할때 무조건 3자리수
            st.push((x % 2));
            x /= 2;
        }
    }
    
    while(st.top() == 0){//반드시 1로 시작하기 위해
        st.pop();
    }

    while(!st.empty()){
        cout << st.top();
        st.pop();
    }

    return 0;
}