#include <iostream>
#include <queue>

using namespace std;

int main(){

    int n, x;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;//최소 힙

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &x);

        if(x == 0){
            if(pq.empty()){
                printf("0\n");
            }
            else{
                printf("%d\n", pq.top().second);//절대값이 가장 작은 값 출력
                pq.pop();//그 값을 배열에서 제거
            }
        }
        else{
            pq.push(make_pair(abs(x), x));
        }
    }


    return 0;
}