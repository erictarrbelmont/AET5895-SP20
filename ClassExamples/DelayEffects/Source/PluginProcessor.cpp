/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DelayEffectsAudioProcessor::DelayEffectsAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

DelayEffectsAudioProcessor::~DelayEffectsAudioProcessor()
{
}

//==============================================================================
const String DelayEffectsAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool DelayEffectsAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool DelayEffectsAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool DelayEffectsAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double DelayEffectsAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int DelayEffectsAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int DelayEffectsAudioProcessor::getCurrentProgram()
{
    return 0;
}

void DelayEffectsAudioProcessor::setCurrentProgram (int index)
{
}

const String DelayEffectsAudioProcessor::getProgramName (int index)
{
    return {};
}

void DelayEffectsAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void DelayEffectsAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    
    Fs = (float)sampleRate;
}

void DelayEffectsAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool DelayEffectsAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void DelayEffectsAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    
    delayLengthSamples = floor(Fs*delayLengthMS/1000.f);
    
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        for (int n = 0 ; n < buffer.getNumSamples(); n++){
            
            float x = buffer.getReadPointer(channel)[n];
            
            // Series
            // Step 1: read from buffer to get output
            //float y = delayBuffer[index][channel];
            
            // Step 2: write into buffer our input
            //delayBuffer[index][channel] = x;
            
            // Step 3: move index
            //if (index < 11999){
            //    index++;
            //}else{
            //    index = 0;
            //}
            
            // Feed-forward Parallel
            // Step 1: read from buffer to get output
            //float y = x + delayBuffer[ index[channel] ][channel];
            
            // Step 2: write into buffer our input
            //delayBuffer[index[channel]][channel] = x;
            
            // Step 3: move index
            //if (index[channel] < MAX_DELAY_LENGTH - 1){
            //    index[channel]++;
            //}else{
            //    index[channel] = 0;
            //}
            
            
            // Feed-back Parallel
            // Step 1: read from buffer to get output
            float y = x + linearGain * delayBuffer[ index[channel] ][channel];
            
            // Step 2: write into buffer our input
            delayBuffer[index[channel]][channel] = y;
            
            // Step 3: move index
            if (index[channel] < delayLengthSamples){
                index[channel]++;
            }else{
                index[channel] = 0;
            }
            
            buffer.getWritePointer(channel)[n] = y;
        }
    }
}

//==============================================================================
bool DelayEffectsAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* DelayEffectsAudioProcessor::createEditor()
{
    return new DelayEffectsAudioProcessorEditor (*this);
}

//==============================================================================
void DelayEffectsAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void DelayEffectsAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new DelayEffectsAudioProcessor();
}
