#include <iostream>
#include <vector>

using namespace std;

bool chk[9] = {false};
vector<int> v;
int n, m;

void backtracking(int cnt){
    
    if(cnt == m){
        for(int i = 0; i < v.size(); i++){
            printf("%d ", v[i]);
        }
        printf("\n");
    }

    for(int i = 1; i <= n; i++){
        if(!chk[i]){
            chk[i] = true;
            v.push_back(i);

            backtracking(cnt+1);
            
            chk[i] = false;
            v.pop_back();
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);

    backtracking(0);

    return 0;
}
