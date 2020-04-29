#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
int a[100];
bool chk[99];
int r, maxi = INT_MIN, mini = INT_MAX;
vector<int> op;//1이면 +, 2이면 -, 3이면 *, 4이면 /
vector<int> v;
int add = 0, sub = 0, multi = 0, divi = 0;

void dfs(int cnt){

    if(cnt == n-1){
        r = a[0];

        for(int i=0; i<n-1; i++){

            if(v[i] == 1) r += a[i+1];
            else if(v[i] == 2) r -= a[i+1];
            else if(v[i] == 3) r *= a[i+1];
            else if(v[i] == 4) r /= a[i+1];
            
        }
        
        maxi = max(maxi, r);
        mini = min(mini, r);

    }

    for(int i=0; i<n-1; i++){
        if(chk[i] == true) continue;

        chk[i] = true;
        v.push_back(op[i]);

        dfs(cnt+1);
        
        chk[i] = false;
        v.pop_back();
    }

}

int main(){

    cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    cin >> add >> sub >> multi >> divi;

    for(int i=0; i<add; i++) op.push_back(1);
    for(int i=0; i<sub; i++) op.push_back(2);
    for(int i=0; i<multi; i++) op.push_back(3);
    for(int i=0; i<divi; i++) op.push_back(4);

    dfs(0);

    cout << maxi << "\n" << mini;
    return 0;
}