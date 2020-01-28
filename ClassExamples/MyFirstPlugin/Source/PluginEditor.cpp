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
}

void MyFirstPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
