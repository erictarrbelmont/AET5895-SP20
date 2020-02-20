//
//  Tremolo.cpp
//
//  Created by Eric Tarr on 2/6/20.
//  Copyright © 2020 Eric Tarr. All rights reserved.
//

#include "Tremolo.hpp"

// Constructor function (special function - no return type, name = Class name)
Tremolo::Tremolo(){
   // No need to do anything with default constructor
}

//Tremolo::Tremolo(float drive){
//    this->drive = drive;
//}

// Destructor
Tremolo::~Tremolo(){
    //cout << "Destructor called" << endl;
}


void Tremolo::processSignal(vector<float> & signal, int numSamples){
    // Where we do our effect
    for (int n = 0; n < numSamples ; n++){
        
        float x = signal[n];
        signal[n] = processSample(x);
    }
}

float Tremolo::processSample(float x){
    
    float lfo;
    
    switch (lfoSelector) {
        case sinewave:
            lfo = amp * sin(currentAngle) + offset;
            break;
        
        case squarewave:
            if (currentAngle < M_PI){
                lfo = 1.0f;
            }
            else{
                lfo = 1.0f - 2.0f*amp;
            }
            break;
        default:
            lfo = amp * sin(currentAngle) + offset;
            break;
    }
    
    
    currentAngle += angleChange;
    if (currentAngle > 2.f * M_PI){
        currentAngle -= 2.f * M_PI;
    }
    
    return x * lfo;
}

void Tremolo::setFs(float Fs){
    this->Fs = Fs;
}


void Tremolo::setSpeed(float speed){
    if (speed >= 0.1f && speed <= 10.0f){
        this->speed = speed;
        angleChange = speed * (1.f/Fs) * 2 * M_PI;
    }
}

void Tremolo::setDepth(float depth){
    if (depth >= 0.0f && depth <= 100.0f){
        this->depth = depth;
        amp = depth/200.0f;
        offset = 1.0f - amp;
    }
}
