//
//  main.cpp
//  백준1339(단어 수학)
//
//  Created by 유영우 on 2021/02/17.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

struct alNum{
    int idx;
    char al;
};

int n;
string str;
vector<alNum>v;
bool check;
int gn=9;
int sum;

bool compare(alNum a, alNum b){
    return a.idx > b.idx;
}

void mkNum(string s){
    for(int i=0;i<s.length();i++){
        for(unsigned j=0;j<v.size();j++){
            if(s[i] == v[j].al){
                v[j].idx+=int(pow(10,s.length()-i-1));
                check = 1;
                break;
            }
        }
        
        if(!check){
            struct alNum al ={int(pow(10,s.length()-i-1)),s[i]};
            v.push_back(al);
        }
        check = 0;
    }
    
}



int main(void) {
    cin >> n;
    for(int i=0;i<n;i++){
        cin >>str;
        mkNum(str);
    }
    sort(v.begin(),v.end(),compare);
    for(unsigned i=0;i<v.size();i++){
        sum+=v[i].idx*gn;
        gn--;
    }
    cout << sum;
    return 0;
}
