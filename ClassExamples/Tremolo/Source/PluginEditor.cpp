/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
TremoloAudioProcessorEditor::TremoloAudioProcessorEditor (TremoloAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);
    
    
    speedSlider.addListener(this);
    speedSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    speedSlider.setBounds(100, 100, 150, 150);
    speedSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 60, 30);
    speedSlider.setRange(0.1f,10.f);
    addAndMakeVisible(speedSlider);
    
    depthSlider.addListener(this);
    depthSlider.setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
    depthSlider.setBounds(225, 100, 150, 150);
    depthSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 60, 30);
    depthSlider.setRange(0.0f,100.f);
    addAndMakeVisible(depthSlider);
    
    
    lfoMenu.addListener(this);
    lfoMenu.addItem("Sine wave", 1);
    lfoMenu.addItem("Square wave", 2);
    lfoMenu.setText("Select LFO");
    lfoMenu.setBounds(150,50,150,40);
    addAndMakeVisible(lfoMenu);
    
    
}

TremoloAudioProcessorEditor::~TremoloAudioProcessorEditor()
{
}

//==============================================================================
void TremoloAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    //g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
}

void TremoloAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}

void TremoloAudioProcessorEditor::sliderValueChanged(Slider * slider){
    
    if (slider == &depthSlider){
        processor.depth = depthSlider.getValue();
    }
    
    if (slider == &speedSlider){
        processor.speed = speedSlider.getValue();
    }
    
}

void TremoloAudioProcessorEditor::comboBoxChanged(ComboBox * comboBox){
        
    if (comboBox == &lfoMenu){
        int selection = lfoMenu.getSelectedId();
        if (selection == 1){
            processor.lfoSelect = Tremolo::LFOType::sinewave;
        }
        else{
            processor.lfoSelect = Tremolo::LFOType::squarewave;
        }
    }
    
}
