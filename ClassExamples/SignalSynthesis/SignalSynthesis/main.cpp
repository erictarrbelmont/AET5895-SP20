//
//  main.cpp
//  SignalSynthesis
//
//  Created by Eric Tarr on 1/21/20.
//  Copyright © 2020 Eric Tarr. All rights reserved.
//

#include <iostream>
#include <cmath>
#include "AudioFile/AudioFile.hpp"
using namespace std;


void square(vector<float> & x,float freq,float A,int Fs, float lenSec);


int main() {
    
    int Fs = 48000;
    int bitDepth = 16;
    int numChannels = 1;
    vector<float> signal;
    
    int lenSec = 3;
    int N = round(lenSec * Fs);
    
    signal.resize(N);
    
    float A = 0.5f;
    float freq = 220.0f;
    
//    float currentAngle = 0.0f;
//    float angleChange = freq * 2.0f * M_PI / (float)Fs ;
//
//    for (int n = 0; n < N; n++){
//        signal[n] = A * sin(currentAngle);
//        currentAngle += angleChange;
//        if (currentAngle > 2.0f*M_PI){
//            currentAngle -= 2.0f*M_PI;
//        }
//    }
    
    square(signal,freq,A,Fs,lenSec);
    
    string outName = "SquareWave.wav";
    audiowrite(outName,signal,Fs,bitDepth,numChannels);
    
    return 0;
}


void square(vector<float> & x,float freq,float A,int Fs, float lenSec){
    
    int N = round(lenSec * Fs);
    float currentAngle = 0.0f;
    float angleChange = freq * 2.0f * M_PI / (float)Fs ;
    
    for (int n = 0; n < N; n++){
        if (currentAngle < M_PI){
            x[n] = A;
        }
        else{
            x[n] = -A;
        }
        currentAngle += angleChange;
        if (currentAngle > 2.0f*M_PI){
            currentAngle -= 2.0f*M_PI;
        }
    }
    
}
