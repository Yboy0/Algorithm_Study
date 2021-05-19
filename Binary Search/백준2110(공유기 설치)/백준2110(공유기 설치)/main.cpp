//
//  main.cpp
//  백준2110(공유기 설치)
//
//  Created by 유영우 on 2021/04/21.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//집 n개:
// 집에 공유기 c개 설치 해야 한다
// 한 집에 공유기 하나 설치 가능
// 가장 인접한 두 공유기 사이의 거리 크게 설치해야 함
// c개의 공유기를 n개의 집에 적당히 설치해야 한다.
// 두 공유기 사이의 거리를 최대로 하는 프로그램을 작성하시오
// n: 집의 개수 c: 공유기 개수

int n,c;
int house;
vector<int>houses;
int low,mid,high;
vector<int>modemHouses; //houses의 index를 넣기
int cnt;
int dist;


bool compare(int a, int b){
    return a<b;
}

void modem(){

    while(low<high){
        
        sort(modemHouses.begin(),modemHouses.end(),compare);
        
        if(c==cnt){
            break;
        }
        
        int dis=0;
        for(unsigned i=1; i<modemHouses.size(); i++){
            if(houses[modemHouses[i]]-houses[modemHouses[i-1]]>dis){
                dis =houses[modemHouses[i]]-houses[modemHouses[i-1]];
                low = modemHouses[i-1];
                high = modemHouses[i];
            }
        }
        
        mid = (low+high)/2;
//        cout<< "high:"<<" "<< high << " "<< "low:" <<" "<<low<<" " << "mid:" << " " << mid << endl;
        modemHouses.push_back(mid);
        cnt++;
        
    }
    
    
}



int main(void) {
    cin >> n >> c;
    for(int i=0; i<n; i++){
        cin >> house;
        houses.push_back(house);
    }
    
    sort(houses.begin(),houses.end(),compare);
    
    low=0;
    high=n-1;
    modemHouses.push_back(low);
    modemHouses.push_back(high);
    cnt+=2;
    dist = houses[high] - houses[low];
    
    
    modem();
    
    for(unsigned i=1; i<modemHouses.size(); i++){
        if(houses[modemHouses[i]]-houses[modemHouses[i-1]]<dist){
            dist =houses[modemHouses[i]]-houses[modemHouses[i-1]];
        }
    }
    
    cout << dist;
   
}
