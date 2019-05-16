//
//  polynomial.cpp
//  polynomial
//
//  Created by 陈俊睿 on 2019/5/12.
//  Copyright © 2019 陈俊睿. All rights reserved.
//

#include <sstream>

#include <cstring>


#include "polynomial.hpp"

using std::cin;
using std::cout;
using std::string;
using std::endl;

int power(int a,int b){int r=1;while(b--)r*=a;return r;}

////////////////////////////////////////////////
//    double x[MAX];
//    std::string name;
////////////////////////////////////////////////

polynomial::polynomial(int c){
    if(c==0){for(int i=0;i<MAX;i++) x[i]=0; name="NULL";}
    if(c==1){name="void";}
};

polynomial::polynomial(string ostr){
    //insert...........
    //4 format :
    //the input example1: P( 4 *x^ 3 +3 )
    //the input example1: P( -4*x +x^7 )
    
    //initialize
    for(int i=0;i<MAX;i++) x[i]=0; name="NULL";
    string part;
    int i,j,k,l;
    double c;
    int p;
    char m;
    std::stringstream ss;
    for(i=2;i<ostr.size()-1;){
        //cut in part
        j=i+1;part="";
        while(ostr[j]!='+'&&ostr[j]!='-'&&ostr[j]!=')')
            j++;
        part=ostr.substr(i,j-i);
        i=j;
        //input from string
        ss.clear();
        ss.str(part);
        for(k=0;k<part.size();k++)if(part[k]=='x')break;
        if (k==part.size()){ss>>c;p=0;}
        else{
            //input c
            for(l=0;l<part.size();l++)if(part[l]=='*')break;
            if (l==part.size()){ss>>m>>m;c=1;}
            else{ss>>c>>m>>m;}
            //input p
            for(l=0;l<part.size();l++)if(part[l]=='^')break;
            if (l==part.size()){p=1;}
            else{ss>>m>>p;}
        }
        x[p]=c;
    }
};

polynomial::polynomial(polynomial &other){for(int i=0;i<MAX;i++) x[i]=other.x[i]; name=other.name;};

polynomial::~polynomial(){};
    
void polynomial::rename(string n){name=n;};
    
polynomial polynomial::operator+(polynomial &other){
    polynomial r(1);
    for(int i=0;i<MAX;i++) r.x[i]=x[i]+other.x[i];
    //for(int i=0;i<MAX;i++) if(r.x[i]==0)r.num++;
    return r;
};

polynomial polynomial::operator-(polynomial &other){
    polynomial r(1);
    for(int i=0;i<MAX;i++) r.x[i]=x[i]+other.x[i];
    //for(int i=0;i<MAX;i++) if(r.x[i]==0)r.num++;
    return r;
};

    //polynomial operator*(polynomial);
    //polynomial operator/(polynomial);
    //polynomial operator%(polynomial);

polynomial& polynomial::operator+=(polynomial &other){
    for(int i=0;i<MAX;i++) x[i]+=other.x[i];
    return *this;
};
polynomial& polynomial::operator-=(polynomial &other){
    for(int i=0;i<MAX;i++) x[i]-=other.x[i];
    return *this;
};


polynomial& polynomial::operator=(polynomial &other){
    //num=other.num;
    for(int i=0;i<MAX;i++)
    x[i]=other.x[i];
    name=other.name;
    return *this;
};
    
    //friend polynomial::polynomial P(string);
    
void polynomial::display(){
    if(name=="void"){cout<<"there is no this polynomial"<<endl;return;}
    int i=MAX-1;
    while(i--){
        if(x[i]!=0){
            if(x[i]>0)cout<<'+';
            if(i==0)cout<<x[i];
            else if(x[i]==1) cout<<"x^"<<i;
            else cout<<x[i]<<"*x^"<<i;
        }
    }
    cout<<endl;
};
int polynomial::result(int x0){
    double r=0;
    for(int i=0;i<MAX;i++){
        if(x[i]!=0) r+=x[i]*power(x0,i);
    }
    return r;
};

polynomial* polynomial::diff(){
    polynomial *n=new polynomial(0);
    int i=MAX-1;
    while(i-->1){
        if(x[i]!=0){
            n->x[i-1]=x[i]*i;
        }
    }
    return n;
};

bool polynomial::operator==(polynomial& other){
    int c=1;
    for(int i=0;i<MAX;i++){
        if(x[i]!=other.x[i])return 0;
    }
    return 1;
};
