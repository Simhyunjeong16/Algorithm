#include <iostream>
#include <string>

using namespace std;

bool DFA(string s){//버전1

    int i = 0;
    int len = s.length();

    while(i < len){

        if(s[i] == '0') {
            if(i+1 >= len) return false;
            if(s[i+1] == '0') return false;
            i += 2;
        }
        else{
            if(i+3 >= len) return false;//100이 최소니까
            if(!(s[i+1] == '0' && s[i+2] == '0')) return false;//뒤에 무조건 00이 두번 나와야 함
            i += 3;

            while(i < len && s[i] == '0') i++;

            if(i == len) return false;//00...00들은 다 추척했더니 끝나버렸다면
            i++;

            while(i < len && s[i] == '1'){
                if(i + 2 < len && s[i+1] == '0' && s[i+2] == '0') break;
                i++;
            }
        }
    }

    return true;
}

int main(){
 
    string str;
    cin >> str;//잠수함의 엔진소리 = (100~1~|01)~
    
    if(DFA(str)) cout << "SUBMARINE";
    else cout << "NOISE";
    
    return 0;
}