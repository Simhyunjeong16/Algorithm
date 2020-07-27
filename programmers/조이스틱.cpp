#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int i = 0;//현재 위치
    string str(name.length(), 'A');//A로 구성된 문자열
    
    while(str != name){
        
        str[i] = name[i];//반영하기

        answer += min(name[i] - 'A', 'Z' - name[i] + 1);//다음 알파벳 vs 이전 알파벳
        
        //왼쪽으로 갈지, 오른쪽으로 갈지 계산
        for(int cnt = 1; cnt < name.length(); cnt++){
            
            //오른쪽 이동이 빠르다면
            if(name[(i + cnt) % name.length()] != str[(i + cnt) % name.length()]){
                i = (i + cnt) % name.length();//오른쪽으로 이동
                answer += cnt;//이동횟수 반영
                break;
            }
            //왼쪽 이동이 빠르다면
            else if(name[(i + name.length() - cnt) % name.length()] != str[(i + name.length() - cnt) % name.length()]){
                i = (i + name.length() - cnt) % name.length();//오른쪽으로 이동
                answer += cnt;//이동횟수 반영
                break;
            }
        }
    }
    

    return answer;
}