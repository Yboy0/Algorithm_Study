//
//  main.cpp
//  백준1931(회의실 배정)
//
//  Created by 유영우 on 2021/02/22.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct clubHouse{
    int start;
    int end;
};



int n;
int cnt=1;
vector<clubHouse> v;

//void compare(){
//    for(int i=0;i<n-1;i++){
//        for(int j=i+1;j<n;j++){
//            clubHouse tmp;
//            if(v[i].end >= v[j].end){
//                if(v[i].end == v[j].end){
//                    if(v[i].start >= v[j].start){
//                        tmp = v[i];
//                        v[i] = v[j];
//                        v[j] = tmp;
//                    }
//                }
//                else{
//                    tmp = v[i];
//                    v[i] = v[j];
//                    v[j] = tmp;
//                }
//
//            }
//
//        }
//
//    }
//
//}

bool compare(clubHouse a, clubHouse b){
    if(a.end == b.end){
        return a.start<b.start;
    }
    else{
        return a.end < b.end;
    }
}

int main(void) {
    cin >> n;
    for(int i=0; i<n; i++){
        clubHouse ch;
        cin >> ch.start >> ch.end;
        v.push_back(ch);
    }
    
//    compare();
    
//    cout << endl;
//    for(int i=0; i<n; i++){
//        cout << v[i].start << " " << v[i].end;
//        cout << endl;
//    }
    
    sort(v.begin(),v.end(),compare);
    
    int crit = v[0].end;
    for(int i=1; i<n; i++){
        if(crit <= v[i].start){
            crit=v[i].end;
            cnt++;
        }
    }
    cout << cnt;
    
    return 0;
}
