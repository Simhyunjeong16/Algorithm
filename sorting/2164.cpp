#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n;
    queue<int> q;

    cin >> n;
    for(int i = 1; i <= n; i++){
        q.push(i);
    }

    while(q.size() != 1){
        q.pop();//제일 위에 있는 카드 버리기
        
        int f = q.front();//제일 위에 있는 카드를 제일 아래에 있는 카드 밑으로 옮기기
        q.pop();
        q.push(f);
    }

    cout << q.front();
    return 0;
}
