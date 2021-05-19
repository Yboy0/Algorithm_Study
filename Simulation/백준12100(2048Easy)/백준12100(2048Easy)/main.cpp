//
//  main.cpp
//  백준12100(2048Easy)
//
//  Created by 유영우 on 2021/05/12.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 전체 블록을 상하좌우 네 방향 중 하나로 이동시키는 것
// 같은 값을 갖는 두 블록이 충돌하면 두 블록은 하나로 합쳐진다.
// 한 번의 이동에서 이미 합쳐진 블록은 또 다른 블록과 다시 합쳐질 수 없다
// 보드의 크기와 보드판의 블록 상태가 주어졌을 때,
//  최대 5번 이동해서 만들 수 있는 가장 큰 블록의 값을 구하라

//0은 빈칸, 나머지 값은 블록
int n;
int num;
int result;

void block(int cnt, int arrr[21][21]){

    
    
}

int main(void) {
    
    int arr[21][21];
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> num;
            arr[i][j]=num;
        }
    }
    
    
    block(0,arr);
    
    cout << result;
    return 0;
}
