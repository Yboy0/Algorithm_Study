//
//  main.cpp
//  백준1744(수 묶기)
//
//  Created by 유영우 on 2021/02/23.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int>v;
vector<int>v1;
int sum;
bool compare(int a, int b){

    return a>b;
}
bool compare1(int a, int b){
    return a<b;
}

int main(void) {
    cin >> n;
    
    for(int i=0;i<n;i++){
        int num;
        cin >> num;
        if(num>0){
            v.push_back(num);
        }else{
            v1.push_back(num);
        }
        
    }
    sort(v.begin(),v.end(),compare);
    sort(v1.begin(),v1.end(),compare1);

    int k=0;
    while(k<v.size()){
       if(k+1<v.size() && v[k]==1 && v[k+1]==1){
           sum+=v[k];
           k+=1;
        }
        else if(k+1<v.size() && v[k]*v[k+1]>v[k]+v[k+1]){
            sum+=v[k]*v[k+1];
            k+=2;
        }
        else{
            sum+=v[k];
            k+=1;
        }
    }
    k=0;
    while(k<v1.size()){
        if(k+1<v1.size() && v1[k]*v1[k+1]>=0){
            sum+=v1[k]*v1[k+1];
            k+=2;
        }
        else{
            sum+=v1[k];
            k+=1;
        }
    }
    cout << sum;
    return 0;
}
