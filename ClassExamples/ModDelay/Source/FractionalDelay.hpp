//
//  FractionalDelay.hpp
//
//  Created by Eric Tarr on 2/6/20.
//  Copyright © 2020 Eric Tarr. All rights reserved.
//

#ifndef FractionalDelay_hpp
#define FractionalDelay_hpp

#include <cmath>
#include <vector>
using namespace std;

class FractionalDelay {
    
public:
    
    // Constructor function (special function - no return type, name = Class name)
    FractionalDelay();
    //Distortion(float drive);
    
    // Destructor
    ~FractionalDelay();
    
    void processSignal(vector<float> & signal, int numSamples, int channel);
    
    float processSample(float x,int channel);

    void setFs(float Fs);
    
    void setDelaySamples(float delay);
    
    void setSpeed(float speed);
    void setDepth(float depth);

    
private:
    
    float Fs = 48000.f;
    
    float delay = 10.f;
    
    const int MAX_BUFFER_SIZE = 30;
    float delayBuffer[30][2] = {0.0f};
    int index[2] = {0};
    
    float speed = 1.0f; // Hz, frequency of LFO
    float depth = 10.0f; // percentage of intensity, control amp of LFO
    
    float amp = depth;
    float offset = amp+1.0f;
    
    float currentAngle = 0.0f;
    float angleChange = speed * (1.f/Fs) * 2 * M_PI;
    
    
    
};



#endif /* FractionalDelay_hpp */