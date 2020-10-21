#include <iostream>
#include <string>
// #include <bits/stdc++.h>//버전2
#include <regex>

using namespace std;

int main(){
 
    string str;
    cin >> str;//잠수함의 엔진소리 = (100~1~|01)~
    
    
    //버전2 (정규표현식 라이브러리)
    regex re("(100+1+|01)+");//~를 +로 바꾸기
    cmatch m;
    bool answer = regex_match(str.c_str(), m, re);
    if(answer) cout << "SUBMARINE";
    else cout << "NOISE";
    
    return 0;
}