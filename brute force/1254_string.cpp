#include <iostream>
#include <string>

using namespace std;
int len;
string str;

bool is_Palin(int x, int len){
    int l = (len - x) / 2;

    for(int i = 0; i < l; i++){
        if(str[i + x] != str[len - 1 - i]){
            return false;
        }
    }
    return true;
}

int main(){
    cin >> str;
    len = str.size();

    for(int i = 0; i < len; i++){
        if(is_Palin(i, len)){//팰린드롬이 시작되는 최소한의 위치 찾기
            cout << len+i;
            break;
        }
    }

    return 0;
}