//
//  main.cpp
//  백준1541(잃어버린 괄호)
//
//  Created by 유영우 on 2021/02/15.
//

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector<char> op;
char num[50];

string str;
int main(void) {
    cin >> str;
    char *buffer = new char[1000];
    strcpy(buffer, str.c_str());
    
    
    for(int i=0; cal.length();i++){
        if(cal[i] == '-' || cal[i] == '+'){
            op.push_back(cal[i]);
        }
        
    }
    num = strtok(cal, "-+");
    while(!num.empty()){
        cout << cal.back();
        cal.pop_back();
    }
    return 0;
}
