#include <iostream>
#include <queue>

using namespace std;

/*
[중간값 구하기 알고리즘]

1) 최대힙의 크기 <= 최소힙의 크기
2) 최대힙의 최대 원소 <= 최소힙의 최소원소
----> 아니라면, 최대힙, 최소힙의 가장 top 값을 swap.
*/

int main(){

    int n, x;
    priority_queue<int, vector<int>, greater<int>> minheap;//최소힙
    priority_queue<int> maxheap;//최대힙

    scanf("%d", &n);

    for(int i = 0; i < n; i++){

        scanf("%d", &x);

        if(maxheap.empty()) maxheap.push(x);
        else if(maxheap.size() == minheap.size()) maxheap.push(x);
        else minheap.push(x);

        if(!maxheap.empty() && !minheap.empty() && maxheap.top() > minheap.top()){
            int a = maxheap.top();
            int b = minheap.top();

            maxheap.pop();
            minheap.pop();

            maxheap.push(b);
            minheap.push(a); 
        }

        printf("%d\n", maxheap.top());
    }
    

    return 0;
}