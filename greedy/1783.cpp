#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;// n x m
    
    if(n == 1){//세로가 1일 경우
        cout << 1 << endl;//시작하는 칸 세기때문에 1
    }
    else if(n == 2){//세로가 2일 경우, 2,3번 방식만 사용, 방문한칸 5개미만이어야함.
        cout << min(4, (m+1)/2) << endl;
    }

    else if(n >= 3){//세로가 3이상 일 경우
        if(m <= 6){
            cout << min(4, m) << endl;
        }
        else{//7이상
            cout << 5+(m-7) << endl;
        }
    }
    

    return 0;
}