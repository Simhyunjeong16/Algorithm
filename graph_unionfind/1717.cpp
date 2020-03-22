#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 1000000 + 1;
int arr[MAX];


int find(int n){//find
    
    if (n == arr[n]) return n;
            
    arr[n] = find(arr[n]);
    return arr[n];
}


void merge(int a, int b){//union
    a = find(a);
    b = find(b);

    arr[b] = a;    
}

void connected(int a, int b){
    a = find(a);
    b = find(b);

    if (a == b){
        printf("YES\n");
    }

    else{
        printf("NO\n");
    }
    
}

int main()
{   

    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i <= n; i++) 
        arr[i] = i; // id 셋팅해주기


    int t, a, b;
    for(int i = 0; i < m; i++){
    
        scanf("%d %d %d", &t, &a, &b);

        if (t == 0){//합집합
            merge(a, b);
        }

        else if (t == 1){//확인하는 연산
           connected(a, b);
        }
    }


    return 0;
}