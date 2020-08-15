#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    while(1){
        int x;
        int answer = 0;

        cin >> x;
        if(x == -1) break;

        vector<int> v;
        v.push_back(x);

        while(1){
            int y;
            cin >> y;
            if(y == 0) break;
            v.push_back(y);
        }
        
        for(int i = 0; i < v.size(); i++){
            auto it = find(v.begin(), v.end(), v[i]*2);//2배인 숫자 찾기
            if(it != v.end()){//찾았다면
                answer++;
            }
        }

        cout << answer << endl;
    }


    return 0;
}