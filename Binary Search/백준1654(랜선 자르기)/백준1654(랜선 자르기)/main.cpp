//
//  main.cpp
//  백준1654(랜선 자르기)
//
//  Created by 유영우 on 2021/05/24.
//
#include <iostream>
using namespace std;

// 캠프 때 쓸 N개의 랜선을 만들어야 함
// 이미 k개의 랜선을 갖고 있음
// k개의 렌선의 길이는 제각각
// k개의 렌선을 N개의 같은 길이의 랜선으로 만들어야 함
// 랜선을 자르거나 만들 때 손실되는 길이는 없다고 가정
// 기존의 k개의 랜선으로 n개의 랜선을 만들 수는 없음
// n개 보다 많이 만드는 것도 n개를 만드는 것에 포함
// 랜선의 길이는 자연수
// 만들 수 있는 최대 랜선의 길이를 구하는 프로그램을 만들자
// 항상 k보다 n이 더 크다

long long  k;
long long n;
long long oh[10001];
long long big;
long long  ans;
long long  low,high,mid;

void line(){
    
    while(low<=high){
        long long cnt=0;
        mid = (high+low)/2;
        
        for(int i=0;i<k;i++){
            cnt += oh[i]/mid;
            //cout << cnt << endl;
        }
       
        if(cnt<n){ //길이 줄여야 함
            high=mid-1;
        }else{ // 길이 늘려야 함
            low=mid+1;
            ans = mid;
        }
        
    }
    
    cout << ans;
}



int main(void) {
    cin >> k >> n;
    
    for(int i=0; i<k; i++){
        cin >> oh[i];
        
        if(oh[i]>big){
            big=oh[i];
        }
    }
    
    low = 1;
    high = big;

    line();
    
    return 0;
}
