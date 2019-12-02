/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    // Make sure you set the size of the component after
    // you add any child components.
    setSize (800, 600);
}

MainComponent::~MainComponent()
{
    // This shuts down the GL system and stops the rendering calls.
    shutdownOpenGL();
}

//==============================================================================
void MainComponent::initialise()
{
    // Initialise GL objects for rendering here.

    openGLContext.setOpenGLVersionRequired(OpenGLContext::OpenGLVersion::defaultGLVersion);
    openGLContext.extensions.initialise();

    auto ver = glGetString(GL_VERSION);

    shaderProgram = new OpenGLShaderProgram(openGLContext);
    
    File myDir(File::getSpecialLocation(File::currentExecutableFile));
    
    File vsFile(myDir.getParentDirectory().getFullPathName() + "/Shaders/Vertex.vert");
    shaderProgram->addVertexShader(vsFile.loadFileAsString());
    
    File fsFile(myDir.getParentDirectory().getFullPathName() + "/Shaders/Fragment.frag");
    shaderProgram->addFragmentShader(fsFile.loadFileAsString());

    isProgramReady = shaderProgram->link();
    if (!isProgramReady) return;

    Vertex2f verts[4] =
    {
        Vertex2f(-1.f, -1.f),
        Vertex2f(1.f, -1.f),
        Vertex2f(1.f, 1.f),
        Vertex2f(-1.f, 1.f)
    };

    openGLContext.extensions.glGenBuffers(1, &vertexBuffer);
    openGLContext.extensions.glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    openGLContext.extensions.glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex2f) * 4, verts, GL_STATIC_DRAW);

    glDisable(GL_DEPTH_TEST);
}

void MainComponent::shutdown()
{
    openGLContext.extensions.glDeleteBuffers(1, &vertexBuffer);

    // Free any GL objects created for rendering here.
    if (isProgramReady)
    {
        shaderProgram->release();
        delete shaderProgram;
        shaderProgram = nullptr;
    }
}

void MainComponent::render()
{
    // This clears the context with a black background.
    OpenGLHelpers::clear (Colours::black);

    // Add your rendering code here...
    if (isProgramReady)
    {
        shaderProgram->use();

        GLint vertexPosition = openGLContext.extensions.glGetAttribLocation(shaderProgram->getProgramID(), "in_position");
        openGLContext.extensions.glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
        openGLContext.extensions.glVertexAttribPointer(vertexPosition, 2, GL_FLOAT, GL_FALSE, 0, nullptr);
        openGLContext.extensions.glEnableVertexAttribArray(vertexPosition);

        GLint mixColorUniform = openGLContext.extensions.glGetUniformLocation(shaderProgram->getProgramID(), "mixColor");
        openGLContext.extensions.glUniform3f(mixColorUniform, 0.f, 0.f, 1.f);

        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    }
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // You can add your component specific drawing code here!
    // This will draw over the top of the openGL background.
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
