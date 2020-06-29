#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;    
    vector<int> student(n, 1);

    for(auto it : lost){
        student[it-1]--;
    }

    for(auto it : reserve){
        student[it-1]++;
    }
    
    for(int i = 0; i < student.size(); i++){//좌측 -> 우측
        if(student[i] != 0) continue;
        
        if(i != 0 && student[i-1] == 2){//맨앞사람 X, 앞사람 여분 O
            student[i-1]--;
            student[i]++;
        }
        else if(i != student.size()-1 && student[i+1] == 2){//맨끝사람 X, 뒷사람 여분 O
            student[i+1]--;
            student[i]++;
        }
    }
    
    for(int i=0; i<student.size(); i++){
        if(student[i] > 0) answer++;
    }
    
    
    return answer ;
}