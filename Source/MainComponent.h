/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent : public OpenGLAppComponent
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

    //==============================================================================
    void initialise() override;
    void shutdown() override;
    void render() override;

    //==============================================================================
    void paint (Graphics& g) override;
    void resized() override;

private:
    //==============================================================================
    // Your private member variables go here...

    struct Vertex2f
    {
        Vertex2f()
        {}

        Vertex2f(GLfloat _x, GLfloat _y)
            : x(_x), y(_y)
        {}

        GLfloat x = 0, y = 0;
    };

    OpenGLShaderProgram* shaderProgram = nullptr;
    GLuint vertexBuffer = 0;
    GLuint VAO = 0;
    bool isProgramReady = false;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
