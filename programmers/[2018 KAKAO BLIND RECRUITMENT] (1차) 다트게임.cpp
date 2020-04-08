#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int x;
    int result;
    int n = 0;//다트를 진행한 게임수
    vector<int> v;
    int num = 0;//0~9와 10을 구분하기 위해서
    
    for(int i=0; i<dartResult.size(); i++){
        
        if(dartResult[i] == 'S'){
            result = x;
            num = 0;
        }
        else if(dartResult[i] == 'D'){
            result = pow(x, 2);   
            num = 0;
        }
        else if(dartResult[i] == 'T'){
            result = pow(x, 3);
            num = 0;
        }

        else if(dartResult[i] == '*'){//2배 곱하기
            result *= 2;
            if(n != 1) v[n-2] *= 2;//첫번째 다트게임빼고 가능, v는 0부터 시작 -> (n-1)-1
                        
        }
        else if(dartResult[i] == '#'){
            result = -result;
        }
        
        else{//숫자
            num++;
            if(num == 2) x = 10; //연속으로 숫자가 나온것은 10밖에 없음
            
            else{
                if(n > 0) v.push_back(result);
                n++;
                x = dartResult[i] -'0';//char -> int
                result = 0;//초기화
            }
            
        }
        
    }

    v.push_back(result);//마지막 값 넣어주기!
    
    for(int i=0; i<v.size(); i++){
        cout << v[i] << "\n";
        answer += v[i];
    }
    
    
    return answer;
}