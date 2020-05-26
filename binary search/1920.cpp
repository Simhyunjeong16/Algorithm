#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

    int n, m, a, find;
    vector<int> v;
    // vector<int>::iterator it;

    cin >> n;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a);
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    scanf("%d", &m);

    for(int i = 0; i < m; i++){
        scanf("%d", &find);

        //lower_bound란? value값을 찾고, 없으면 value값 보다 큰 가장 작은 정수를 찾는다.
        auto it = lower_bound(v.begin(), v.end(), find);
        //auto를 쓰거나 vector<int>::iterator it;를 쓰기

        if(*it == find){
            printf("1\n");
        }
        else{ 
            printf("0\n");    
        }
    }


    return 0;
}