//
//  main.cpp
//  백준20055(컨베이어 벨트 위의 로봇)
//
//  Created by 유영우 on 2021/05/02.
//

#include <iostream>
using namespace std;


//1번 칸이 있는 위치: 올리는 위치, N번 칸이 있는 위치: 내리는 위치
// 로봇은 올리는 위치에서 올리고 내리는 위치에서 내리고
// 로봇을 올리거나 로봇이 이동하면 칸의 내구도는 -1

//1/ 벨트가 로봇과 함께 한 칸 회전. 내리는 위치 로봇은 내린다
//2/ 로봇이동 로봇이동 조건
    //1. 내리는 위치가 아니고
    //2. 다음 칸에 로봇이 없고
    //3. 칸의 내구도가 1이상

//3/올리는 위치 칸의 내구도가 0이 아니면 올리는 위치에 로봇올림
//4/내구도가 0인 칸이 k개 이상이면 과정을 종료. 아니면

// result: 종료되었을 멏번째 단계인지


int n;
int k; // 칸 내구도 0인게 k개 이상이면 종료
int arr[2][101]; // 내구도
int rb[2][101]; // 로봇

//올리는 위치: (1,1) 내리는 위치: (n,n)
void robot(int type){
    int count=0;
    for(int i=1; i<=2; i++){
        for(int j=1; j<=n; j++){
            if(arr[i][j] == 0){
                count++;
            }
        }
    }
    //종료
    if(count>=k){
        cout << type;
        return;
    }else{
        if(type ==1){ //밸트의 회전(내구도 변경), 밸트의 회전
          //벨트의 회전
            int cnt=0;
            int y=1,x=1;
            int temp =arr[1][1];
            while(cnt<=2*n){
                if(y==1){
                    if(x==n){
                        int temp1 = arr[y+1][x];
                        arr[y+1][x] = temp;
                        temp= temp1;
                        x--;
                        cnt++;
                    }else{
                        int temp1 = arr[y][x+1];
                        arr[y][x+1] = temp;
                        temp = temp1;
                        x++;
                        cnt++;
                    }
                }else if(y==2){
                    if(x==1){
                        arr[y-1][x] = temp;
                        cnt++;
                        
                    }else{
                        int temp1 = arr[y+1][x];
                        arr[y][x-1] = temp;
                        temp = temp1;
                        x--;
                        cnt++;
                    }
                }
            }
            if(rb[n][n] == 1){
                rb[n][n]=0;
            }
            robot(2);
        }else if(type ==2){//로봇의 이동
            for(int i=1; i<=2; i++){
                for(int j=1; j<=n; j++){
                    //이동
                    if(rb[i][j] ==1 && rb[i][j+1] ==0 && arr[i][j+1] >=1){
                        if(!(i==1 && j==n)){
                            rb[i][j]=0;
                            rb[i][j+1]=1;
                            
                        }
                       
                    }
                }
            }
        }else if(type==3){
            if(arr[1][1]!=0){
                rb[1][1]=1;
            }
            robot(1);
        }
     
    }
    
    
    
    
    
}

int main(void) {
    cin >> n >> k;
    
    for(int i=1; i<=2; i++){
        for(int j=1; j<=n; j++){
            cin >> arr[i][j];
        }
    }
    
    robot(1);
}
