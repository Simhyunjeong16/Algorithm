#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    vector<pair<int, int>> a;
    int x, y;
    for(int i=0; i<n; i++){
        scanf("%d %d", &x, &y);
        a.push_back(make_pair(y, x));//secone, first(내가 자리바꿈)
    }
    
    sort(a.begin(), a.end());

    queue<int> q;
    q.push(a[0].first);

    for(int i=1; i<n; i++){

        if(q.back() <= a[i].second){
            q.push(a[i].first);
        }
    }


    cout << q.size();
    return 0;
}