#include <iostream>
#include <deque>

using namespace std;

int main(){
    int n, m, pos;
    deque<int> dq;
    int cnt = 0;

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        dq.push_back(i);
    }

    while(m--){
        cin >> pos;

        int idx = 1;

        for(int i = 0; i < dq.size(); i++){//뽑아내야 할 위치(index) 찾기
            if(dq[i] == pos) break;
            idx++;
        }

        int left = idx - 1;//왼쪽으로 몇 칸 이동?
        int right = dq.size() - idx + 1;//오른쪽으로 몇 칸 이동?

        if(left < right){//왼쪽 연산(2번)
            
            for(int j = 1; j <= left; j++){
                dq.push_back(dq.front());
                dq.pop_front();
                cnt++;
            }
            dq.pop_front();//1번 연산
        }  
        else{//오른쪽 연산(3번)
        
            for(int j = 1; j <= right; j++){
                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            }
            dq.pop_front();//1번 연산
        }

    }

    cout << cnt;
    return 0;
}
