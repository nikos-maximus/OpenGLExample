#version 330 core
in vec2 in_position;
out vec2 waveformUV;

void main()
{
   waveformUV.x = (in_position.x + 1.0) * 0.5;
   waveformUV.y = in_position.y;
   gl_Position = vec4(in_position, 0.0, 1.0);
}
