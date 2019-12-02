#version 330 core
in vec2 in_position;
out vec2 waveformUV;

void main()
{
   waveformUV = (in_position + 1.0) * 0.5;
   gl_Position = vec4(in_position, 0.0, 1.0);
}
