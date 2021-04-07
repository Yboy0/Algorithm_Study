//
//  main.cpp
//  백준2579(계단 오르기)
//
//  Created by 유영우 on 2021/04/07.
//

#include <iostream>
#include <algorithm>
using namespace std;


//계단은 한 번에 한 계단 or 두 계단
// 연속된 세 계단 밟으면 안됨
// 시작점은 계단 포함 X
// 마지막은 꼭 밟아야 한다
// 최대 점수가 나오는 프로그렘
int dp[301][2];
int arr[301];
int n;


void state(int num){
    dp[1][0]=arr[1];
    dp[1][1]=arr[1];
    dp[2][0]=arr[2];
    
    for(int i=1; i<num; i++){
        for(int j=0; j<2; j++){
            if(j==0){// [i+1][1], [i+2][0] //연속으로 뛰지 않은 경우
                if(dp[i+1][1]<dp[i][j]+arr[i+1]){
                    dp[i+1][1] = dp[i][j]+arr[i+1];
                }
                if(dp[i+2][0]<dp[i][j]+arr[i+2]){
                    dp[i+2][0] = dp[i][j]+arr[i+2];
                }
                
            }else{//j는 1일 때 [i+2][0] //연속으로 뛴 경우
                if(dp[i+2][0]<dp[i][j]+arr[i+2]){
                    dp[i+2][0] = dp[i][j]+arr[i+2];
                }
            }
        }
    }
}

int main(void) {
    cin >> n;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
        
    state(n);
        
    cout << max(dp[n][0],dp[n][1]);
    return 0;
}
