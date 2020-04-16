/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "SimpleMeter.h"

//==============================================================================
/**
*/
class PitchShifterAudioProcessorEditor  : public AudioProcessorEditor,
                                            public Slider::Listener,
                                            public Timer
{
public:
    PitchShifterAudioProcessorEditor (PitchShifterAudioProcessor&);
    ~PitchShifterAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void sliderValueChanged(Slider * slider) override;
    void timerCallback() override;
private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    PitchShifterAudioProcessor& processor;

    Slider pitchKnob;
    
    Slider gainKnob;
    
    SimpleMeter meter;
    
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> sliderAttachment;
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PitchShifterAudioProcessorEditor)
};
