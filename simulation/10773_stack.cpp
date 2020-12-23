#include <iostream>
#include <stack>

using namespace std;

int main(){
    int k;
    stack<int> st;
    int sum = 0;

    cin >> k;

    while(k--){
        int x;
        cin >> x;

        if(x == 0) st.pop();
        else st.push(x); 
    }

    while(!st.empty()){
        sum += st.top();
        st.pop();
    }

    cout << sum;
}
