#include <iostream>
#include <algorithm>


using namespace std;

int w[1000001];
int n;

int main(){

    cin >> n;//저울추의 개수
    
    for(int i=0; i<n; i++){
        cin >> w[i]; //저울추의 무게
    }

    sort(w, w+n);//1 1 2 3 6 7 30

    int result = 1;//미리 1더해놓기!
    for(int i=0; i<n; i++){
        if(result < w[i]) break;

        result += w[i];
    }


    cout << result << endl;

    return 0;
}