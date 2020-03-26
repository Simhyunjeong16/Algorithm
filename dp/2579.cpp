#include <iostream>
#include <algorithm>

using namespace std;

int N;//계단의 개수
int d[10000001];//i번째 계단까지의 최대값을 저장해놓는 배열
int s[10000001];//문제에서 주어지는 점수를 저장한 배열

int dp(){

    int Jumsu;
    for(int i=0; i<N; i++){
        cin >> Jumsu;
        s[i] = Jumsu;//10 20 15 25 10 20
    }

    //1칸을 갔을 때
    d[0] = s[0];

    //2칸을 갔을 때
    d[1] = max(s[0]+s[1], s[1]);//1칸+1칸, 2칸

    //3칸을 갔을 때
    d[2] = max(s[0]+s[2], s[1]+s[2]);//1칸+2칸, 2칸+1칸


    for(int i=3; i<N; i++){

        d[i] = max(d[i-3]+s[i-1]+s[i], d[i-2]+s[i]);
        // d[i-3]+r[i-1]+r[i] = 전전전칸까지의 최댓값 + 전칸 + 현재칸
        // d[i-2]+r[i] = 전전칸까지의 최댓값 + 현재칸
    }

    
    return d[N-1];//0부터 시작했으니까 1을 빼야한다.
}

int main(){

    cin >> N;

    cout << dp() << endl;
    
    return 0;
}