//
//  main.cpp
//  AudioExample
//
//  Created by Hack Audio on 10/5/19.
//  Copyright © 2019 Eric Tarr. All rights reserved.
//

#include <iostream>
#include <cmath>
#include "AudioFile/AudioFile.hpp"
using namespace std;


void dBAmpChange(vector<float> & x, const float dBAmp);

void stereoWidener(vector<vector<float>> & x, const float width);


int main() {
    
    string filename = "AcGtr.wav";
    int Fs;
    int bitDepth;
    int numChannels;
    vector<float> signal;
    
    //audioread(filename,signal,Fs,bitDepth,numChannels);
    
//    int N = signal.size(); // length(signal)
//
//    for (int n = 0; n < N ; n++){
//        signal[n] *= 0.25; // signal[n] = signal[n] * 0.25;
//    }
    
//    float dBAmp = -24.0f;
//    dBAmpChange(signal, dBAmp);
    
    //string outName = "Test.wav";
    
    //audiowrite(outName,signal,Fs,bitDepth,numChannels);
    
    //float stereoSignal[2][4] = {0.0f};
    //stereoSignal[1][3] = 5.0f;
    
    string stereoFilename = "stereoDrums.wav";
    vector<vector<float>> stereoSignal;
    audioread(stereoFilename,stereoSignal,Fs,bitDepth,numChannels);
    
    float width = 0.0f; // 0 - 2
    stereoWidener(stereoSignal, width);

//
    string outName = "Test.wav";
    audiowrite(outName,stereoSignal,Fs,bitDepth,numChannels);
    
    
    return 0;
}

void dBAmpChange(vector<float> & x, const float dBAmp){
    
    float linAmp = pow(10.0f , (dBAmp/20.0f) );
    
    int N = x.size();
    for (int n = 0; n < N ; n++){
        x[n] *= linAmp;
    }
    
}


void stereoWidener(vector<vector<float>> & x, const float width){
    
    vector<float> sides;
    vector<float> mids;
    
    int N = x[0].size();
    
    sides.resize(N);
    mids.resize(N);
    
    for (int n = 0; n < N; n++){
        sides[n] = 0.5f*(x[0][n] - x[1][n]);
        mids[n] = 0.5f*(x[0][n] + x[1][n]);
        
        sides[n] *= width;
        mids[n] *= (2.0f - width);
        
        x[0][n] = sides[n] + mids[n];
        x[1][n] = sides[n] - mids[n];
        
    }
    
    
    
    
}

