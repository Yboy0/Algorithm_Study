//
//  main.cpp
//  백준15649
//
//  Created by 유영우 on 2021/01/30.
//

#include <iostream>
#include <vector>
using namespace std;

int n,m;
bool check=false;

void sequence(vector<int> v,int sz){
    check = false;
    int csz=sz;
    if(sz == m){
        for(int i=0; i<m; i++){
            //cout << v[i] << " ";
            printf("%d ",v[i]);
        }
        //cout << endl;
        printf("\n");
    }
    else{
        for(int i=1;i<n+1;i++){
            if(csz>0){
                for(int j=0;j<csz;j++){
                    if(v[j] == i){
                        check=true;
                        break;
                    }
                }
            
            }
            if(!check){
                v.push_back(i);
                sequence(v,++sz);
                v.pop_back();
                sz--;
            }
            check=false;
                
        }

    }

}

int main(void) {
    vector<int> v;
    scanf("%d %d",&n,&m);
    sequence(v,0);
    return 0;
}
