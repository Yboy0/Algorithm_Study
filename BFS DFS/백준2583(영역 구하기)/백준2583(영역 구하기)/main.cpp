//
//  main.cpp
//  백준2583(영역 구하기)
//
//  Created by 유영우 on 2021/03/02.
//

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
int m,n,k; // m: y, n: x
int a,b,c,d;

int arr[200][200];
bool check[200][200];
vector<int>v;
int cnt;

bool compare(int a, int b){
    return a<b;
}

void place(int y, int x){
    check[y][x]=true;
    cnt++;
    if(y+1<m && arr[y+1][x]==0 && check[y+1][x]==false){
        place(y+1,x);
    }
    if(x+1<n && arr[y][x+1]==0 && check[y][x+1]==false){
        place(y,x+1);
    }
    if(x-1>=0 && arr[y][x-1]==0 && check[y][x-1]==false){
        place(y,x-1);
    }
    if(y-1>=0 && arr[y-1][x]==0 && check[y-1][x]==false){
        place(y-1,x);
    }
    
}


int main(void) {
    cin >> m >> n >> k; // 0 2 4 4 -> 0,2 0,4 4,2 4,4 (x,y)
    for(int i=0;i<k;i++){
        cin >> a >> b >> c >> d;
        for(int j=b;j<d;j++){
            for(int k=a;k<c;k++){
                arr[j][k]=1;
            }
        }
    }
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==0 && check[i][j]==false){
                cnt=0;
                place(i,j);
                v.push_back(cnt);
            }
        }
    }
    
    
    sort(v.begin(),v.end(),compare);
    cout << v.size() << endl;
    
    for(unsigned i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    
    return 0;
}
