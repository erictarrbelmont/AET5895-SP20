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
    SoftClip(float drive);
    
    // Destructor
    ~SoftClip();
    
    void processSignal(vector<float> & signal, int numSamples) override;

    void setDrive(float drive) override;
    
private:
    
    float drive = 1.0f;
    
};



#endif /* Distortion_hpp */
