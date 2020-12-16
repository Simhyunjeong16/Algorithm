#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    string alphabet  = "abcdefghijklmnopqrstuvwxyz";

    cin >> s;

    for(int i = 0; i < alphabet.size(); i++){
        cout << (int)s.find(alphabet[i]) << " ";//원하는 문자열이 없을 경우 npos(-1)
    }
    //find함수는 최초로 등장하는 위치의 index를 반환하는 함수

    return 0;
}
