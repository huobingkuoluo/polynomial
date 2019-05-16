//
//  polynomial.hpp
//  polynomial
//
//  Created by 陈俊睿 on 2019/5/12.
//  Copyright © 2019 陈俊睿. All rights reserved.
//

#ifndef polynomial_hpp
#define polynomial_hpp

#include <stdio.h>
#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::string;
using std::endl;

#define MAX 100

using std::string;

class polynomial{
private:
    //int num;
    double x[MAX];
    std::string name;
public:
    //polynomial();
    polynomial(int x);
    polynomial(string);
    ~polynomial();
    polynomial(polynomial &);
    
    void rename(string);
    string getname(){return name;};
    
    polynomial operator+(polynomial&);
    polynomial operator-(polynomial&);
    polynomial operator*(polynomial);
    polynomial operator/(polynomial);
    
    polynomial& operator+=(polynomial&);
    polynomial& operator-=(polynomial&);
    
    polynomial& operator=(polynomial&);
    bool operator==(polynomial&);

    polynomial* diff();
    
    //friend polynomial P(string);
    
    void display();
    int result(int x0);
};
#endif /* polynomial_hpp */
