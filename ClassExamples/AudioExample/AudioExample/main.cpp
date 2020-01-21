//
//  main.cpp
//  AudioExample
//
//  Created by Hack Audio on 10/5/19.
//  Copyright © 2019 Eric Tarr. All rights reserved.
//

#include <iostream>
#include "AudioFile/AudioFile.hpp"
using namespace std;

int main() {
    
    string filename = "AcGtr.wav";
    int Fs;
    int bitDepth;
    int numChannels;
    vector<float> signal;
    
    audioread(filename,signal,Fs,bitDepth,numChannels);
    
    int N = signal.size(); // length(signal)
    
    for (int n = 0; n < N ; n++){
        signal[n] *= 0.25; // signal[n] = signal[n] * 0.25;
    }
    
    
    //float stereoSignal[2][4] = {0.0f};
    //stereoSignal[1][3] = 5.0f;
    
    string stereoFilename = "stereoDrums.wav";
    vector<vector<float>> stereoSignal;
    audioread(stereoFilename,stereoSignal,Fs,bitDepth,numChannels);
    
    N = stereoSignal[0].size();
    
    // Process each sample in both the left and right channels
    for (int c = 0; c < numChannels ; c++){
        for (int n = 0; n < N ; n++){
            stereoSignal[c][n] *= 0.25f;
        }
    }
    
    string outName = "Test.wav";
    audiowrite(outName,stereoSignal,Fs,bitDepth,numChannels);
    
    
    return 0;
}
