#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct info
{   string name;
    int day;
    int month;
    int year;
};

bool cmp(const info& x, const info& y){
    if(x.year == y.year){
        if(x.month == y.month){
            return x.day < y.day;
        }
        return x.month < y.month;
    }
    return x.year < y.year;
}

int main(){
    int student;
    vector<info> v;
    string n;
    int d, m, y;

    cin >> student;

    for(int i = 0; i < student; i++){
        cin >> n >> d >> m >> y;
        v.push_back({n, d, m, y});
    }

    sort(v.begin(), v.end(), cmp);//나이많은 사람 ~ 나이적은 사람

    cout << v.back().name << "\n" << v.front().name << "\n";

    return 0;
}