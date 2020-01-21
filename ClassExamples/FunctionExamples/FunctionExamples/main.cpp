//
//  main.cpp
//  FunctionExamples
//
//  Created by Eric Tarr on 1/16/20.
//  Copyright © 2020 Eric Tarr. All rights reserved.
//

#include <iostream>
using namespace std;

float myFunction1(float x); // declaration

void myFunction2(float &x, const float y); // function passing in a reference


int main() {
    
    float a = 2.0f;
    float b;
    
    const float c = 11.0f;
    //c = 8;
    
    b = myFunction1(a);
    
    // Reference in C++
    //float * c = &b;
    
    //cout << "Value of b is: " << b << endl;
    //cout << "Reference of b is: " << c << endl;
    
    myFunction2(a,c);
    
    return 0;
}


float myFunction1(float x){
    // Passing value to function
    // Will not overwrite value in "main"
    float y = 10.f;
    
    x = y;
    
    return 1.0f;
    
}


void myFunction2(float &x, const float y){
    
    x = 10.0f + y;
    // no return necessary
}
