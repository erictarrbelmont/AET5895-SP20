//
//  main.cpp
//  AudioOOP
//
//  Created by Eric Tarr on 2/6/20.
//  Copyright © 2020 Eric Tarr. All rights reserved.
//

// This project demonstrates how to create a distortion
// effect as a "class"

#include <iostream>
#include <cmath>
#include "AudioFile/AudioFile.hpp"
#include "Distortion.hpp"
using namespace std;

int main() {
    
    string filename = "AcGtr.wav";
    int Fs;
    int bitDepth;
    int numChannels;
    vector<float> signal;
    
    audioread(filename,signal,Fs,bitDepth,numChannels);
    
    int numSamples = signal.size();
    
    {
    //Distortion distortion;
    Distortion distortion(3.0f);
    distortion.setDrive(5.0f);
    distortion.processSignal(signal, numSamples);
    }
    
    string outputFilename = "newSig.wav";
    audiowrite(outputFilename,signal,Fs,bitDepth,numChannels);
    
    return 0;
}







