//
//  main.cpp
//  백준1946(신입사원)
//
//  Created by 유영우 on 2021/02/22.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Company{
    int papers;
    int interview;
};

int t;
bool compare(Company a, Company b){
    return a.papers<b.papers;
}
void New(vector<Company>v,int n){
    int crt = v[0].interview;
    int cnt = n;
    for(int i=1;i<n;i++){
        if(v[i].interview > crt){
            cnt--;
        }
        else{
            crt = v[i].interview;
        }
    }
    cout << cnt;
}

int main(void) {
    cin >> t;
    for(int i=0;i<t;i++){
        int n;
        vector<Company> v;
        cin >> n;
        for(int j=0;j<n;j++){
            Company company;
            cin>>company.papers>>company.interview;
            v.push_back(company);
        }
        sort(v.begin(),v.end(),compare);
        New(v,n);
        cout << endl;
    }
    return 0;
}
