#include <iostream>
#include <climits>

using namespace std;

int n;
int a[100];
int maxi = INT_MIN, mini = INT_MAX;
int add = 0, sub = 0, multi = 0, divi = 0;

void dfs(int ad, int su, int mu, int di, int sum, int i, int cnt){

    if(cnt == n-1){
        
        maxi = max(maxi, sum);
        mini = min(mini, sum);

        return;
    }


    if(ad < add) dfs(ad+1, su, mu, di, sum+a[i], i+1, cnt+1);
    
    if(su < sub) dfs(ad, su+1, mu, di, sum-a[i], i+1, cnt+1);
    
    if(mu < multi) dfs(ad, su, mu+1, di, sum*a[i], i+1, cnt+1);
    
    if(di < divi) dfs(ad, su, mu, di+1, sum/a[i], i+1, cnt+1);

}

int main(){

    cin >> n;
 
    for(int i=0; i<n; i++) cin >> a[i];
    cin >> add >> sub >> multi >> divi;

    dfs(0, 0, 0, 0, a[0], 1, 0);

    cout << maxi << "\n" << mini;
    return 0;
}