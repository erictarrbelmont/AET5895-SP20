//
//  main.cpp
//  DistortionExamples
//
//  Created by Eric Tarr on 1/21/20.
//  Copyright © 2020 Eric Tarr. All rights reserved.
//

#include <iostream>
#include "AudioFile/AudioFile.hpp"
using namespace std;

void fullwaveRectify(vector<float> &x);

void fullwaveRectify(vector<vector<float>> &x);


int main() {
    
    string filename = "stereoDrums.wav";
    int Fs;
    int bitDepth;
    int numChannels;
    vector<vector<float>> signal;
    
    audioread(filename,signal,Fs,bitDepth,numChannels);
    
    fullwaveRectify(signal);
    
    string outName = "Test.wav";
    
    audiowrite(outName,signal,Fs,bitDepth,numChannels);
    
    return 0;
}

void fullwaveRectify(vector<float> & x){
    int N = x.size();
    
    for (int n=0 ; n < N ; n++){
        
        if (x[n] < 0.0f){
            //x[n] = abs(x[n]);
            x[n] *= -1.0f;
        }
        
    }
}


void fullwaveRectify(vector<vector<float>> & x){
    int N = x[0].size();
    
    for (int c=0 ; c < 2 ; c++){
        for (int n=0 ; n < N ; n++){
            if (x[c][n] < 0.0f){
                //x[c][n] = abs(x[c][n]);
                x[c][n] *= -1.0f;
            }
        }
    }
}


