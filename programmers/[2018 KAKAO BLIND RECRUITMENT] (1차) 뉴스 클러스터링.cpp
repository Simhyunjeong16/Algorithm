#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> s1;
    vector<string> s2;
    
    //대문자로 변경해주기
    for(int i=0; i<str1.size(); i++) str1[i] = toupper(str1[i]);
    for(int i=0; i<str2.size(); i++) str2[i] = toupper(str2[i]);
    
    
    for(int i=0; i<str1.size()-1; i++){
        if(str1[i+1] >= 'A' && str1[i+1] <= 'Z' && str1[i] >= 'A' && str1[i] <= 'Z'){
            s1.push_back(str1.substr(i, 2));//i번째부터 2길이만큼 자르기
        }
    }
               

    for(int i=0; i<str2.size()-1; i++){
        if(str2[i+1] >= 'A' && str2[i+1] <= 'Z' && str2[i] >= 'A' && str2[i] <= 'Z'){
            s2.push_back(str2.substr(i, 2));//i번째부터 2길이만큼 자르기
        }
    }

    
    int a = 0;//교집합 개수
    for(int i=0; i<s1.size(); i++){
        for(int j=0; j<s2.size(); j++){
            if (s1[i] == s2[j]){
                a++;
                s2[j] = "0";//가져갔다는 의미로 임의의 숫자(0) 삽입
                break;
            }
        }
    }
    
    int b = (s1.size() + s2.size()) - a; //합집합 개수
    float f;
    if(a == 0 && b == 0) f = 1;
    else f = static_cast<float> (a)/b;//int -> float 형변환 == (float)a/b;


    answer = f*65536;
    
    return answer;
}