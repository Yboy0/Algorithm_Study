//
//  main.cpp
//  백준2110(공유기 설치)
//
//  Created by 유영우 on 2021/04/21.
//

#include <iostream>
#include <algorithm>
using namespace std;


int n; // 집의 개수
int c; // 공유기 개수
// 가장 인접한 두 공유기 사이의 거리를 최대로
int house[200001];
int result;

void modem(int begin, int end, int cnt){
    
    int mid = (end-(begin))/2;
    
    if(cnt<=3){
        result = min(house[end]-house[mid],house[mid]-house[begin]);
    }else{
        if(house[end]-house[mid]>house[mid]-house[begin]){
            modem(mid,end,cnt-(cnt/2));
        }else{
            modem(begin,mid,cnt-(cnt/2));
        }
    }
    
    
}


int main(void) {
    
    cin >> n >> c;
    
    for(int i=0; i<n; i++){
        cin >> house[i];
    }
    
    sort(house,house+n);
    modem(0,n-1,c);
    
    cout << result;
    return 0;
}
