//
//  main.cpp
//  백준14889(스타트와 링크)
//
//  Created by 유영우 on 2021/04/14.
//

#include <iostream>
using namespace std;

int n;
int arr[21][21];
bool check[22];
int answer;
void team(int cnt,int idx){
    
    if(cnt == n/2){
        int link = 0,start=0;
        for(int i=1; i<=n-1; i++){
            for(int j=i+1; j<=n;j++){
                if(check[i]==true && check[j]==true){
                    link+=arr[i][j]+arr[j][i];
                }else if(check[i]==false && check[j]==false){
                    start+=arr[i][j]+arr[j][i];
                }
            }
        }
        answer=min(answer,abs(start-link));
    }
    else{
        for(int i=idx;i<=n;i++){
            if(check[i]==false){
                check[i]=true;
                team(cnt+1,i+1);
                check[i]=false;
            }
        }
    }
    
    
}

int main(void) {
   
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> arr[i][j];
            answer+=arr[i][j];
        }
    }
    
    check[1]=true;
    team(1,1);

    printf("%d",answer);
    return 0;
}
