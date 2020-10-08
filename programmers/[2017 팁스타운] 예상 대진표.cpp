using namespace std;

int solution(int n, int a, int b){
    int answer = 1;

    while(1){
        a = (a / 2) + (a % 2);
        b = (b / 2) + (b % 2);
        
        if(a == b) break;
        else answer++;
    }
    
    return answer;
}

