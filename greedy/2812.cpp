#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> a;
int n, k;
string r;

int main(){

    cin >> n >> k;
    cin >> r;

    
    for(int i=0; i<n; i++){

        int tmp = r[i]-'0';
        
        while( !a.empty() && k != 0 && a.back() < tmp){
            a.pop_back();
            k--;
        }

        a.push_back(tmp);
    }

    
    while(k != 0){
        a.pop_back();
        k--;
    }

    for(int i=0; i<a.size(); i++) {
        cout << a[i];
    }

    return 0;
}