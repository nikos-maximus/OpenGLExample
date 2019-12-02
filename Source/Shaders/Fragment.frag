#version 330 core
in vec2 waveformUV;
out vec4 fragColor;

void main()
{
   fragColor = vec4(waveformUV, 0.0, 1.0);
}
