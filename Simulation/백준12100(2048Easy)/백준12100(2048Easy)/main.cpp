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

// 한 번의 이동은 보드 위 상하좌우 네 방향 중 하나로 이동하는 것
// 이동 할 떄 같은 값을 갖는 두 블록이 충돌하면 두 블록은 하나로 합쳐진다.
// 한 번의 이동에서 이미 합쳐진 블록은 또 다른 블록 다시 합쳐질 수 없다.

int n;
int num;
int result;

void block(int cnt, int arrr[21][21]){
    if(cnt==5){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arrr[i][j]>result){
                    result = arrr[i][j];
                }
            }
        }
        return;
        
    }else{
        for(int u=0;u<4;u++){ //상하좌우
            //배열 복사
            int copyArr[21][21];
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    copyArr[i][j]=arrr[i][j];
                }
            }
            
            if(u==0){ //상
                for(int i=0;i<n;i++){ //x축
                        int idx=-1;
                    for(int j=1;j<n;j++){ //y축
                        int move=j;
                        bool check=false;
                        if(copyArr[j][i]>0){ //이동
                            //합쳐지는 경우
                            for(int k=j-1;k>idx;k--){
                                if(copyArr[j][i]==copyArr[k][i]){
                                    copyArr[k][i]*=2;
                                    copyArr[j][i]=0;
                                    idx=k;
                                    check=true;
                                    break;
                                }else if(copyArr[k][i]==0){
                                    move=k;
                                }else{ //바로 앞에 다른 수일 경우 이동 못함
                                    break;
                                }
                            }
                            //그냥 이동
                            if(move!=j && !check){
                                copyArr[move][i]=copyArr[j][i];
                                copyArr[j][i]=0;
                            }
                        }
                        
                    }
                }
                block(cnt+1,copyArr);
            }else if(u==1){ //하
                for(int i=0;i<n;i++){ //x축
                    int idx=n;
                    for(int j=n-2;j>-1;j--){ //y축
                        int move=j;
                        bool check=false;
                        if(copyArr[j][i]>0){
                            for(int k=j+1;k<idx;k++){
                                if(copyArr[j][i]==copyArr[k][i]){
                                    copyArr[k][i]*=2;
                                    copyArr[j][i]=0;
                                    idx=k;
                                    check=true;
                                    break;
                                }else if(copyArr[k][i]==0){
                                    move=k;
                                }else{ //다른 수일 경우
                                    break;
                                }
                            }
                            if(move!=j && !check){
                                copyArr[move][i]=copyArr[j][i];
                                copyArr[j][i]=0;
                            }
                        }
                    }
                }
                block(cnt+1,copyArr);
            }else if(u==2){ //좌
                for(int i=0;i<n;i++){
                    int idx=-1;
                    for(int j=1;j<n;j++){
                        int move=j;
                        bool check=false;
                        if(copyArr[i][j]>0){
                            for(int k=j-1;k>idx;k--){
                                if(copyArr[i][j]==copyArr[i][k]){
                                    copyArr[i][k]*=2;
                                    copyArr[i][j]=0;
                                    idx=k;
                                    check=true;
                                    break;
                                    
                                }else if(copyArr[i][k]==0){
                                    move=k;
                                }else{ //다른 수일 경우
                                    break;
                                }
                            }
                            if(move!=j && !check){
                                copyArr[i][move]=copyArr[i][j];
                                copyArr[i][j]=0;
                            }
                        }
                    }
                }
                block(cnt+1,copyArr);
            }else{ //우
                for(int i=0;i<n;i++){
                    int idx=n;
                    for(int j=n-2;j>-1;j--){
                        int move=j;
                        bool check=false;
                        if(copyArr[i][j]>0){
                            for(int k=j+1;k<idx;k++){
                                if(copyArr[i][j]==copyArr[i][k]){
                                    copyArr[i][k]*=2;
                                    copyArr[i][j]=0;
                                    idx=k;
                                    check=true;
                                    break;
                                    
                                }else if(copyArr[i][k]==0){
                                    move=k;
                                }else{ //다른 수일 경우
                                    break;
                                }
                            }
                            if(move!=j && !check){ //위에 0이 있거나 합쳐 지지 않은 경우에 이동해야함
                                copyArr[i][move]=copyArr[i][j];
                                copyArr[i][j]=0;
                            }
                            
                        }
                    }
                }
                block(cnt+1,copyArr);
            }
        }
    }
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
