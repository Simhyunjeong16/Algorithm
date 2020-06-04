#include <iostream>

using namespace std;

int N;
int arr[15];//열의 개수
int answer = 0;

bool chk(int i){

    for(int j = 0; j < i; j++){//0부터 i-1 열까지 검사
        if(arr[j] == arr[i]) return false;//새로운 퀸과 기존의 퀸이 같은 열에 있는 경우
        if(abs(arr[i]-arr[j]) == i-j) return false;//같은 대각선에 있는 경우
    }
    return true;//퀸 놓을 수 있다
}


void nqueen(int i){//백트래킹

    if(i == N){//끝까지 다 돌았다면
        answer++;
        return;
    }

 
    for(int j = 0; j < N; j++){
       arr[i] = j;

       if(chk(i)) nqueen(i+1);//true면 다음 퀸 찾기, false면 백트래킹
    }

}

int main(){

    cin >> N;//퀸은 대각선, 직선(행, 열) 방향 공격

    nqueen(0);

    cout << answer;   
    return 0;
}