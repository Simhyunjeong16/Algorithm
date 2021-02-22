#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){

    int a, b, c;
    vector<char> v = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int cnt[10] = {0, };

    cin >> a >> b >> c;

    int result = a * b * c;
    string answer = to_string(result);

    for(auto it : answer){
        for(int j = 0; j < 10; j++){
            if(it == v[j]){
                cnt[j]++;
            }
        }
    }
    
    for(int j = 0; j < 10; j++){
        cout << cnt[j] << endl;
    }

    return 0;
}
