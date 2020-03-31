#include <iostream>
#include <string>

using namespace std;

//마이너스가 한번이라도 등장한 시점부터는 그 뒤로 이어진 모든 숫자들은
//부호에 상관없이 모두 마이너스로 처리할 수 있다!

int main(){

    string a;
    cin >> a;

    int result = 0;
    string temp;
    bool minus = false;

    for(int i=0; i<=a.size(); i++){

        if(a[i] == '+' || a[i] == '-' || a[i] == '\0'){
            
            if(minus == true)
                result += -stoi(temp);
            else 
                result += stoi(temp);

            if(a[i] == '-') minus = true;

            temp="";
            continue;
        }

        temp += a[i];//숫자를 temp에 저장하는구나
    }
    
    cout << result << endl;

    return 0;
}