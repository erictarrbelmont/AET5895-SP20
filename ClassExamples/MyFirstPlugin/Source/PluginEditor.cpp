/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MyFirstPluginAudioProcessorEditor::MyFirstPluginAudioProcessorEditor (MyFirstPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (600, 300);
    
    gainSlider.addListener(this);
    gainSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    gainSlider.setBounds(300,100,150,150);
    gainSlider.setRange(1.0f,10.0f);
    gainSlider.setValue(processor.gainMultiplier);
    gainSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 50, 30);
    addAndMakeVisible(gainSlider);
    
    polarityButton.addListener(this);
    polarityButton.setBounds(100, 100, 40, 40);
    addAndMakeVisible(polarityButton);
    
    
}

MyFirstPluginAudioProcessorEditor::~MyFirstPluginAudioProcessorEditor()
{
}

//==============================================================================
void MyFirstPluginAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::yellow);
    g.setFont (25.0f);
    //g.drawFittedText ("My First Plug-in", getLocalBounds(), Justification::centred, 1);
    g.drawFittedText("My First Plugin",20, 20, 400, 100, Justification::centred, 1);
    
    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText("Polarity",120, 105, 60, 30, Justification::centred, 1);
}

void MyFirstPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}


void MyFirstPluginAudioProcessorEditor::sliderValueChanged(Slider* slider){
    
    if (slider == &gainSlider){
        processor.gainMultiplier = gainSlider.getValue();
    }
     
}

void MyFirstPluginAudioProcessorEditor::buttonClicked(Button* button){
    
    if (button == &polarityButton){
        //float test = polarityButton.getToggleState();
        processor.polarityMultiplier *= -1.0f;
    }
}
