#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int pos = -1;
    
    for(int i = 0; i < number.size() - k; i++){//필요한 글자 수 만큼 반복
        char max = 0;
        
        for(int j = pos+1; j<= k+i; j++){//앞에 있는 숫자 중에 젤 큰 숫자 찾기
            if(max < number[j]){
                max = number[j];
                pos = j;
            }
        }
        answer += max;
    }
    
    
    return answer;
}