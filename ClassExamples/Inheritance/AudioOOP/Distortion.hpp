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
    Distortion(float drive);
    
    // Destructor
    ~Distortion();
    
    // Add "virtual" keyword so that we can override in sub class
    virtual void processSignal(vector<float> & signal, int numSamples);

    virtual void setDrive(float drive);
    
private:
    
    float drive = 1.0f;
    
};



#endif /* Distortion_hpp */
