//
//  main.cpp
//  HelloWorld
//
//  Created by Eric Tarr on 1/9/20.
//  Copyright © 2020 Eric Tarr. All rights reserved.
//


#include <iostream>
#include <cmath>
using namespace std;


// Functions
// First declare our function

// [y] = dBAmpChange(x,dBAmp)
float dBAmpChange(float x, float dBAmp);


int main() {
    // insert code here...
    
    cout << "Hello, World!" << endl;
    
    // Data type (int, float, double, long, bool)
    int a = 5; // declared and defined in one command
    
    int b; // declare
    b = 6; // define
    
    cout << a << " " << b << endl;
    
    float c;
    c = 3.14;
    
    double d = -5.67;
    
    float x[5] = {0.0}; // initialize all to be zero
    x[0] = 6;
    x[1] = 3;
    x[2] = 7;
    
    
    // Control structures
    
    // Conditional statement
    if (d < 0){
        int t = 1;
    }
    else if(d > 10){
        double h = 100;
    }
    else{
        float g = 0.5;
    }
        
    // FOR loop
    //for n = 1:2:10
    //
    //end
        // start loop ; end loop ; increment
    float sample;
    float dBAmp = -6.0f;
    for (int n = 0 ; n < 5 ; n++){
       // Special syntax for incrementing
       // n = n+1
       // n++ (same thing)
       sample = x[n];
        x[n] = dBAmpChange(sample, dBAmp);
    }
    // Other special operations
    // n--
    
    // h = n++ * 10
    
    // n = n * 10
    // n *= 10
    
    // n += 10  -> n = n+10
    
    // WHILE Loop
    int i = 0;
    while ( i < 5){
        sample = x[i];
        //i = i + 1;
        i++;
    }
    
    return 0;
}

// Function definition
float dBAmpChange(float x, float dBAmp){
    
    // linAmp = 10^(dBAmp/20)
    float linAmp = pow(10.0f,(dBAmp/20.0f));
    
    float y = linAmp * x;
    
    return y;
}

