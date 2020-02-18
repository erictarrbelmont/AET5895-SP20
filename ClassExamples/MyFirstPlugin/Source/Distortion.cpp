//
//  Distortion.cpp
//  AudioOOP
//
//  Created by Eric Tarr on 2/6/20.
//  Copyright © 2020 Eric Tarr. All rights reserved.
//

#include "Distortion.hpp"

// Constructor function (special function - no return type, name = Class name)
Distortion::Distortion(){
   // No need to do anything with default constructor
}

Distortion::Distortion(float drive){
    this->drive = drive;
}

// Destructor
Distortion::~Distortion(){
    //cout << "Destructor called" << endl;
}


void Distortion::processSignal(vector<float> & signal, int numSamples){
    // Where we do our effect
    for (int n = 0; n < numSamples ; n++){
        
        float x = signal[n];
        //signal[n] = (2.0f/M_PI) * atan(drive * x);
        signal[n] = processSample(x);
    }
}

float Distortion::processSample(float x){
    
    return (2.0f/M_PI) * atan(drive * x);
}

void Distortion::setDrive(float drive){
    if (drive >= 1.0f && drive <= 10.0f){
        this->drive = drive;
    }
}

