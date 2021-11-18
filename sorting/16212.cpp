#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int a[500001];
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a+n);

    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }

    return 0;
}
