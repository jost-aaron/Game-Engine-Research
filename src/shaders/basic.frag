// #version 130
//
// uniform vec4 color = vec4(1.0,0.0,0.0,1.0);
// uniform vec2 light_pos;
//
// in vec4 vs_out_position;
// in vec4 vs_out_color;
//
// void main(){
//
//     float intensity = (1/length(vs_out_position.xy-light_pos))/*0.75*/;
//
//     gl_FragColor = vs_out_color*intensity;
//       // gl_FragColor = vs_out_color;
// }

#version 330
layout (location=0) out vec4 color;

uniform vec4 colour;
uniform vec2 light_pos;

in DATA {
  vec4 position;
  vec4 color;
} fs_in;

void main(){

    float intensity = (1/length(fs_in.position.xy-light_pos))*4;
    color = fs_in.color*intensity;
}
