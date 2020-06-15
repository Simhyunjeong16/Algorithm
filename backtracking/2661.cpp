#include <iostream>
#include <string>

using namespace std;

int n;
bool flag = false;

void backtracking(int x, string str){
    if(flag) return;//str찾았으니 종료하자

    //나쁜 수열
    int len = str.size();
    for(int i = 1; i <= (len/2); i++){
        if(str.substr(len-i, i) == str.substr(len-(2*i), i)){
            return;
        }
    }


    //길이완성
    if(x == n){
        cout << str;
        flag = true;//하나만 찾으면 되니까 종료시키기 위해서
        return;
    }


    for(int i=1; i<=3; i++){
        backtracking(x+1, str+to_string(i));
    }

}


int main(){
    cin >> n;
    
    backtracking(0, "");

    return 0;
}