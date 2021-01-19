#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct person{
    int country, student, score;
};

bool cmp(person x, person y){
    return x.score > y.score;
}

int main(){
    int n;
    cin >> n;

    vector<person> v(n);
    map<int, int> m;

    for(int i = 0; i < n; i++){
        cin >> v[i].country >> v[i].student >> v[i].score;
    }

    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i <= 1; i++){
        m[v[i].country]++;
        cout << v[i].country << " " << v[i].student << "\n";
    }


    for(int i = 2; i < n; i++){
        if(m[v[i].country] == 2) continue;
        
        cout << v[i].country << " " << v[i].student;
        return 0;
    }

}
