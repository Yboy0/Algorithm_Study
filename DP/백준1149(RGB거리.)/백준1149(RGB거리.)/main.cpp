//
//  main.cpp
//  백준1149(RGB거리.)
//
//  Created by 유영우 on 2021/05/30.
//

#include <iostream>
using namespace std;

// rgb거리에 집이 n개
// 집은 r,g,b 중 하나의 색으로 칠해야 함
// 각각의 집을 빨, 초, 파로 칠하는 비용이 주어지면 규칙에 만족하는 모든 집을 칠하는 비용의 최솟값 구하기
    // 1번 잡의 색은 2번 집의 색과 같지 않아야 함
    // n번 집의 색은 n-1번 잡의 색과 같지 않아야 함
    // i번 집의 색은 i-1, i+1 집의 색과 같지 않아야 함

// 비용의 최솟값 구하기
int n;
int pay[1001][3]; // rgb로 집 칠하는 비용들
int dp[1001][3];

int main(void) {
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0;j<3;j++){
            cin >> pay[i][j];
        }
    }
    
    dp[0][0]=pay[0][0];
    dp[0][1]=pay[0][1];
    dp[0][2]=pay[0][2];
    
    for(int i=1; i<n; i++){
        for(int j=0; j<3;j++){
            
            if(j==0){
                dp[i][1]=dp[i-1][j]+pay[i][1];
                dp[i][2]=dp[i-1][j]+pay[i][2];
            }else if(j==1){
                dp[i][0]=dp[i-1][j]+pay[i][0];
                if(dp[i][2]>dp[i-1][j]+pay[i][2]){
                    dp[i][2]=dp[i-1][j]+pay[i][2];
                }
               
            }else{
                if(dp[i][0]>dp[i-1][j]+pay[i][0]){
                    dp[i][0]=dp[i-1][j]+pay[i][0];
                }
                if(dp[i][1]>dp[i-1][j]+pay[i][1]){
                    dp[i][1]=dp[i-1][j]+pay[i][1];
                }
            }
    }
}
    
    int min=dp[n-1][0];
    for(int i=1;i<3;i++){
        if(dp[n-1][i]<min){
            min = dp[n-1][i];
        }
    }
    
    cout << min;
}
