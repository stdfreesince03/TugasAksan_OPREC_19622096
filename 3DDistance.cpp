#include <iostream>
#include <bits/stdc++.h>
#include<cstdio>
using namespace std;

string removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

void printEl(vector<int> v){
    for(int i = 0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}

int power(int num,int powerTo){
    int value = 1;
    for(int i = 0;i<powerTo;i++){
        value*=num;
    }
    return value;
}

int main(){
   string pos1,pos2;
   vector<int> p1,p2;

   getline(cin,pos1);
   pos1 = removeSpaces(pos1);
   stringstream ss1(pos1);
   for(int i ;ss1>>i;){
     p1.push_back(i);
     if(ss1.peek()== ','){
       ss1.ignore();
     }
   }
   
   getline(cin,pos2);
   pos2 = removeSpaces(pos2);
   stringstream ss2(pos2);
   for(int i ;ss2>>i;){
     p2.push_back(i);
     if(ss2.peek()== ','){
       ss2.ignore();
     }
   }

   int distance;
   if(p1.size() == p2.size() && p1.size() == 3){
        for(int  i = 0;i<p1.size();i++){
            int absNow = abs(p1[i] - p2[i]) ;
            distance += power(absNow,2);
        }
   }
    
   printf("%.2f\n",sqrt(distance));
   

   
   
 
}

