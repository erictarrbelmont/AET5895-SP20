/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class TremoloAudioProcessorEditor  : public AudioProcessorEditor,
                                     public Slider::Listener,
                                     public ComboBox::Listener
                                     //public Button::Listener
{
public:
    TremoloAudioProcessorEditor (TremoloAudioProcessor&);
    ~TremoloAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

    void sliderValueChanged(Slider* slider) override;
    void comboBoxChanged(ComboBox * comboBox) override;
    
private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    TremoloAudioProcessor& processor;

    Slider speedSlider;
    Slider depthSlider;
    
    ComboBox lfoMenu;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TremoloAudioProcessorEditor)
};
