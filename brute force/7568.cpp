#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int>> v;
vector<int> vct;

int n, x, y;

int main(){
    cin >> n;//전체 사람의 수

    for(int i=0; i<n; i++){
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }


    for(int i=0; i<n; i++){

        int k = 0;//등수
        int w = v[i].first;//몸무게
        int h = v[i].second;//키
        
        for(int j=0; j<n; j++){
            if(i == j) continue;//자기자신

            if (w < v[j].first && h < v[j].second){
                k++;
            }
        }

        vct.push_back(k+1);
    }


    for(int i=0; i<n; i++)
        cout << vct[i] << " ";
    
    return 0;
}