#include <string>
#include <vector>

using namespace std;

string Convert(int num, int n){
    char c[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    
    string res = "";
    int a;//나머지
    
    while(num / n != 0){
        a = num % n;
        res = c[a] + res;//나머지들의 역순이므로 앞에다가 삽입
        num = num / n;
    }
    res = c[num % n] + res;//몫이 0일때, 나머지를 추가해준다
    
    return res;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string str = "";
    
    for(int i = 0; i < t*m; i++){//모든 게임 인원이 참가하는 str 구하기
        str += Convert(i, n);
    }
    
    p -= 1;//0부터 시작하니까
    for(int i = 0; i < t; i++){
        answer += str[p];
        p += m;
    }
    
    return answer;
}
