#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int k, n, x;
    cin >> k;

    for(int i = 1; i <= k; i++){
        cin >> n;

        vector<int> v;
        for(int j = 0; j < n; j++){
            cin >> x;
            v.push_back(x);
        }
        
        sort(v.begin(), v.end(), greater<int>());
        
        int gap = 0;
        for(int a = 1; a < v.size(); a++){
            gap = max(gap, abs(v[a-1] - v[a]));
        }

        cout << "Class " << i << "\n";
        cout << "Max " << v.front() << ", Min " << v.back() << ", Largest gap " << gap << "\n";  
    }

    return 0;
}