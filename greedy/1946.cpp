#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>> a;
int other_method(){
    int T;
    cin >> T;//테스트 케이스의 개수

    while(T--) {
        a.clear();
        int n, min=100001, result = 0;
        cin >> n;

        for(int i=0; i<n; i++){
            int x,y;
            cin >> x >> y;
            a.push_back(make_pair(x,y));//한쌍으로 만들어준다!!!!
        }
        
        sort(a.begin(), a.end());//오름차순으로 정렬합니다.

        for(int i=0; i<n; i++){
            if(min > a[i].second){
                min = a[i].second;
                result++;
            }
        }

        cout << result;
    }
}

int main(){

    int T;
    cin >> T;//테스트 케이스의 개수

    
    for(int i=0; i<T; i++){
        int N;
        cin >> N;//지원자의 숫자
    
        int a, b;
        int num[N+1];
        for(int j= 0; j<N; j++){  
            cin >> a >> b;//서류성적 순위, 면접성적 순위
            num[a] = b;
        }


        int count = 1;
        int tmp = num[1];
        for(int x=2; x<=N; x++){
            if (num[x] < tmp) {
                count++;
                tmp = num[x];
            }
        }

        cout << count << endl;
    }

    return 0;
}