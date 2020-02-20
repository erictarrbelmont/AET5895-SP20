//
//  Distortion.hpp
//  AudioOOP
//
//  Created by Eric Tarr on 2/6/20.
//  Copyright © 2020 Eric Tarr. All rights reserved.
//

#ifndef Distortion_hpp
#define Distortion_hpp

#include <cmath>
#include <vector>
using namespace std;

// General "Base" Class
class Distortion {
    
public:
    
    // Constructor function (special function - no return type, name = Class name)
    Distortion();
    
    // Destructor
    ~Distortion();
    
    // Add "virtual" keyword so that we can override in sub class
    
    // Pure virtual function must be overriden
    virtual void processSignal(vector<float> & signal, int numSamples) = 0; // 0 makes it "pure"

    // Not a pure virtual, includes implementation
    virtual void setDrive(float drive){
        this->drive = drive;
    };
    
private:
    
    float drive = 1.0f;
    
};



#endif /* Distortion_hpp */
