//
//  main.cpp
//  백준1931(회의실배정)
//
//  Created by 유영우 on 2021/02/18.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct clubHouse{
    int start;
    int end;
};

int n; //회의 수
int st;
int en;
int clubCnt;
vector<clubHouse> v;

bool compare(clubHouse a, clubHouse b){
    return a.start<b.start;
    
};

void cntClub(int idx,int cnt){
    if(v[idx].end >= v[v.size()-1].start){
        if(cnt>clubCnt){
            clubCnt=cnt;
        }
        return;
    }
    else{
        for(unsigned i =idx;i<v.size()-1;i++){
            for(unsigned j=i+1;j<v.size();j++){
                if(v[i].end < v[j].start){
                    cntClub(j, cnt+1);
                }
            }
            if(cnt == 0){
                cntClub(i+1, cnt+1);
            }
        }
    }
}
  

//최대 사용할 수 있는 회의 최대 개수
int main(void) {
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        scanf("%d %d",&st,&en);
        struct clubHouse clubhouse={st,en};
        v.push_back(clubhouse);
    }
    sort(v.begin(),v.end(),compare);
    
//    for(int i=0;i<v.size();i++){
//        cout << v[i].start << " "<< v[i].end;
//        cout << endl;
//    }
    cntClub(0, 0);
    cout << clubCnt;
    
    return 0;
}
