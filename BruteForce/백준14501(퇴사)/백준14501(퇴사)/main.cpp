//
//  main.cpp
//  백준14501(퇴사)
//
//  Created by 유영우 on 2021/04/30.
//

#include <iostream>
#include <vector>

using namespace std;

struct Advice{
    int date;
    int money;
};

int maxMon;
int n,a,b;
vector<Advice> v;

void leave(int idx, int mon){
    if(idx+v[idx].date >= n){
        if(idx+v[idx].date==n){
            mon = mon+v[idx].money;
        }
        if(mon>maxMon){
            maxMon=mon;
        }
        return;
    }
    else{
        mon = mon+v[idx].money;
        for(int i=idx+v[idx].date; i<n; i++){
            leave(i,mon);
        }
    }
}

int main(void) {
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> a >> b;
        Advice advice  ={a,b};
        v.push_back(advice);
    }
    
    for(int i=0; i<n; i++){
        leave(i,0);
    }

    
    cout << maxMon;
    
    return 0;
}
