//
//  main.cpp
//  UserDataTypes
//
//  Created by Eric Tarr on 2/4/20.
//  Copyright © 2020 Eric Tarr. All rights reserved.
//

#include <iostream>
using namespace std;

class Grades{
// Rule of thumb: make set/get methods public
public:
    
    void setHW1Grade(float grade){
        // Check if valid
        if (grade <= 100.0f && grade >= 0.0f){
            hw1 = grade;
        }
        else{
            hw1 = 100.0f;
        }
    }
    
    float getHW1Grade(){
        return hw1;
    }
    
private:
    // Member variables private
    float hw1;
    float hw2;
    float midterm;
    
};


// Define AudioInfo structure
struct AudioInfo{
    int bitDepth;
    int numSamples = 100;
    int numChannels = 2;
    string filename = "AcGtr.wav";
};

int main() {

    // Make an instance of AudioInfo
    AudioInfo audioInfo;
    
    audioInfo.bitDepth = 16;
    
    // Multiple Instances
    AudioInfo audio2;
    audio2.bitDepth = 24;
    
//    cout << audioInfo.filename << endl;
//    cout << audioInfo.numChannels << endl;
//    cout << audioInfo.bitDepth << endl;
//    cout << audio2.bitDepth<< endl;
    
    // Create an "object" of the class, "instance" of class
    Grades myGrade;
    Grades friendsGrade;
    
    myGrade.setHW1Grade(100.0f);
    
    float test = myGrade.getHW1Grade();
    
    friendsGrade.setHW1Grade(90.0f);
    
    float test2 = friendsGrade.getHW1Grade();
    
    cout << test << endl;
    cout << test2 << endl;
    
    
    return 0;
    
}
