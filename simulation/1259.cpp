#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;

    while(cin >> str){
        if(str == "0") break;

        bool flag = true;
        for(int i = 0; i < str.length()/2; i++){
            if(str[i] != str[str.length()-1-i]){
                flag = false;
                break;
            }
        }

        if(flag) cout << "yes" << endl;
        else cout << "no" << endl;

    }
    return 0;
}