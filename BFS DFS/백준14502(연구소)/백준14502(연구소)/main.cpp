//
//  main.cpp
//  백준14502(연구소)
//
//  Created by 유영우 on 2021/03/02.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//0: 빈칸 1: 벽 2: 바이러스

struct Coord{
    int y;
    int x;
};


int n,m;
int arr[10][10];
bool checkV[10][10];
bool check[10][10];
bool checkVV[10][10];
int cnt;
vector<Coord>v;
vector<int> v1;
vector<Coord>v2;

bool compare(int a, int b){
    return a>b;
}



void safeZone(int y, int x){
    check[y][x]=true;
    cnt++;
    if(y+1<n && arr[y+1][x]==0 && check[y+1][x]==false){
        safeZone(y+1, x);
    }
    if(y-1>=0 && arr[y-1][x]==0 && check[y-1][x]==false){
        safeZone(y-1, x);
        
    }
    if(x+1<m && arr[y][x+1]==0 && check[y][x+1]==false){
        safeZone(y, x+1);
        
    }
    if(x-1>=0 && arr[y][x-1]==0 && check[y][x-1]==false){
        safeZone(y, x-1);
    }
}

void virus(int y, int x){
    checkV[y][x]=true;
    arr[y][x] = 2;
    
    if(y+1<n && arr[y+1][x]==0 && checkV[y+1][x]==false){
        virus(y+1, x);
    }
    if(y-1>=0 && arr[y-1][x]==0 && checkV[y-1][x]==false){
        virus(y-1, x);
        
    }
    if(x+1<m && arr[y][x+1]==0 && checkV[y][x+1]==false){
        virus(y, x+1);
        
    }
    if(x-1>=0 && arr[y][x-1]==0 && checkV[y][x-1]==false){
        virus(y, x-1);
    }
}


int main(void) {
    cin >> n >> m; // n:y m:x
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    
    //벽새우기
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 0){
                Coord coord = {i,j};
                v.push_back(coord);
            }
            
        }
    }
    for(unsigned i=0;i<v.size()-2;i++){
        for(unsigned j=i+1;j<v.size()-1;j++){
            for(unsigned k=j+1;k<v.size();k++){
               
                arr[v[i].y][v[i].x]=1;
                arr[v[j].y][v[j].x]=1;
                arr[v[k].y][v[k].x]=1;
                //
                for(int l=0;l<n;l++){
                    for(int o=0;o<m;o++){
                        if(arr[l][o]==2 && checkV[l][o]==false){
                            virus(l,o);
                            checkVV[l][o]=true;
//                            Coord coord = {l,o};
//                            v2.push_back(coord);
                        }
                    }
                }
                
                for(int p=0;p<n;p++){
                    for(int q=0;q<m;q++){
                        if(arr[p][q]==0 && check[p][q]==false){
                            safeZone(p,q);
                        }
                    }
                }
//                cout << cnt << " ";
                v1.push_back(cnt);
                cnt=0;
                arr[v[i].y][v[i].x]=0;
                arr[v[j].y][v[j].x]=0;
                arr[v[k].y][v[k].x]=0;
                
                for(int r=0;r<n;r++){
                    for(int s=0;s<m;s++){
                        check[r][s]=false;
                        checkV[r][s]=false;
                        if(arr[r][s]==2){
                            if(checkVV[r][s]==false){
                                arr[r][s]=0;
                            }
                            else{
                                checkVV[r][s]=false;
                            }
                            
                        }
                       
                    }

                }
                
            }
        }
    }
    
    sort(v1.begin(),v1.end(),compare);
    cout << v1[0];
    return 0;
}
