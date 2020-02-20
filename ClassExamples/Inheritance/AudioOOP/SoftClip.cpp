//
//  SoftClip.cpp
//  AudioOOP
//
//  Created by Eric Tarr on 2/6/20.
//  Copyright © 2020 Eric Tarr. All rights reserved.
//

#include "SoftClip.hpp"

// Constructor function (special function - no return type, name = Class name)
SoftClip::SoftClip(){
   // No need to do anything with default constructor
}

// Destructor
SoftClip::~SoftClip(){
    //cout << "Destructor called" << endl;
}


void SoftClip::processSignal(vector<float> & signal, int numSamples){
    // Where we do our effect
    for (int n = 0; n < numSamples ; n++){
        
        float x = signal[n];
        signal[n] = (2.0f/M_PI) * atan(drive * x);
    }
}

void SoftClip::setDrive(float drive){
    if (drive >= 1.0f && drive <= 10.0f){
        this->drive = drive;
    }
}

