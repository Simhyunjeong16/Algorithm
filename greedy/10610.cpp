#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

//미르코는 30배수 덕후.
//각 숫자 자릿수의 합이 3의 배수라면, 전체숫자는 항상 3의 배수가 된다 (정수론)
//30의 배수이기 때문에 3 x 10으로 생각해야해서 0이 들어가야한다.

vector<int> d;
int main(){

    string n;
    cin >> n;

    int r = 0;
    bool ten = false;

    for(int i=0; i<n.size(); i++){
        
        int x = n[i]-'0'; //char문자를 정수형으로 변환!!! 
          
        r += x;
        d.push_back(x);
        if(x == 0) ten = true;
    }

    if(r%3 == 0 && ten == true){
        sort(d.begin(), d.end(), greater<int>());

        for(int i=0; i<d.size(); i++)
            cout << d[i];
    }

    else{
        cout << -1 << endl;
    }
    
    return 0;
}