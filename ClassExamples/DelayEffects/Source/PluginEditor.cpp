/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DelayEffectsAudioProcessorEditor::DelayEffectsAudioProcessorEditor (DelayEffectsAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    delayKnob.addListener(this);
    delayKnob.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    delayKnob.setBounds(50,75,150, 150);
    delayKnob.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 25);
    delayKnob.setRange(50,1000);
    addAndMakeVisible(delayKnob);
    
    gainKnob.addListener(this);
    gainKnob.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    gainKnob.setBounds(200,75,150, 150);
    gainKnob.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 25);
    gainKnob.setRange(0,0.9);
    addAndMakeVisible(gainKnob);
    
}

DelayEffectsAudioProcessorEditor::~DelayEffectsAudioProcessorEditor()
{
}

//==============================================================================
void DelayEffectsAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    //g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
}

void DelayEffectsAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}


void DelayEffectsAudioProcessorEditor::sliderValueChanged(Slider * slider){
    
    if (slider == &delayKnob){
        processor.delayLengthMS = delayKnob.getValue();
    }
    
    if (slider == &gainKnob){
        processor.linearGain = gainKnob.getValue();
    }
}











