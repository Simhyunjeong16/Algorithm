#include <iostream>

using namespace std;

int main(){
    int t, n, x;

    scanf("%d", &t);

    for(int i = 0; i < t; i++){
        cin >> n;

        int min = 1000001, max = -1000001;
        for(int j = 0; j < n; j++){
            
            scanf("%d", &x);

            if(min > x) min = x;
            if(max < x) max = x;
        }
        
        printf("%d %d \n", min, max);
    }

    return 0;
}