//
//  SoftClip.hpp
//  AudioOOP
//
//  Created by Eric Tarr on 2/6/20.
//  Copyright © 2020 Eric Tarr. All rights reserved.
//

#ifndef SoftClip_hpp
#define SoftClip_hpp

#include <cmath>
#include <vector>
#include "Distortion.hpp"

using namespace std;

class SoftClip : public Distortion {
    
public:
    
    // Constructor function (special function - no return type, name = Class name)
    SoftClip();
    
    // Destructor
    ~SoftClip();
    
    // Because this is a "pure" virtual function in base class,
    // we must implement it in derive class
    void processSignal(vector<float> & signal, int numSamples) override;

    // It is not necessary to implement, but we can if we want
    void setDrive(float drive) override;
    
    void newMethod(); // Methods don't need to be in base class.
    
private:
    
    float drive = 1.0f;
};



#endif /* Distortion_hpp */
