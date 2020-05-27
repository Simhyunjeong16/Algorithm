#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n, m, x, find;
    vector<int> v;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    scanf("%d", &m);

    for(int i = 0; i<m; i++){
        scanf("%d", &find);

        auto it = lower_bound(v.begin(), v.end(), find);

        if(*it == find){
            printf("1 ");
        }
        else{
            printf("0 ");
        }

    }


    return 0;
}