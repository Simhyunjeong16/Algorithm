#include <iostream>
#include <queue>

using namespace std;

int main(){

    priority_queue<int, vector<int>, greater<int>> pq;

    int n, x;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> x;
        pq.push(x);
    }

    int answer = 0;
    while(pq.size() != 1){

        int result = 0;
        for(int i = 0; i < 2; i++){
            result += pq.top();
            pq.pop();
        }
        
        answer += result;
        pq.push(result);
    }

    cout << answer;
    return 0;
}