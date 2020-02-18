//
//  Tremolo.hpp
//
//  Created by Eric Tarr on 2/6/20.
//  Copyright © 2020 Eric Tarr. All rights reserved.
//

#ifndef Tremolo_hpp
#define Tremolo_hpp

#include <cmath>
#include <vector>
using namespace std;

class Tremolo {
    
public:
    
    // Constructor function (special function - no return type, name = Class name)
    Tremolo();
    //Distortion(float drive);
    
    // Destructor
    ~Tremolo();
    
    void processSignal(vector<float> & signal, int numSamples);
    
    float processSample(float x);

    void setFs(float Fs);
    void setSpeed(float speed);
    void setDepth(float depth);
    
private:
    
    float Fs = 48000.f;
    
    float speed = 1.0f; // Hz, frequency of LFO
    float depth = 100.0f; // percentage of intensity, control amp of LFO
    
    float amp = depth/200.f;
    float offset = 1.0f - amp;
    
    float currentAngle = 0.0f;
    float angleChange = speed * (1.f/Fs) * 2 * M_PI;
    
};



#endif /* Tremolo_hpp */
