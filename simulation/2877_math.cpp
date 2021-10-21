#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int k;
    string str = "";//2진수로 변환된 숫자 문자열
    string ans = "";
    
    cin >> k;
    k = k + 1;//1을 2진수(0)으로 생각하고 풀기

    //2진수로 변환
    while(k > 0){
        str += ((k % 2) + '0');
        k /= 2;
    }
    reverse(str.begin(), str.end());
    
    //제일 앞자리 수 제외하기
    for(int i = 1; i < str.size(); i++){
        if(str[i] == '0') ans += '4';
        else ans += '7'; 
    }

    cout << ans;
    return 0;
}
