#version 130

uniform vec4 color = vec4(1.0,0.0,0.0,1.0);
uniform vec2 light_pos;

in vec4 vs_out_position;
in vec4 vs_out_color;

void main(){

    float intensity = (1/length(vs_out_position.xy-light_pos))*0.5;

    gl_FragColor = vs_out_color*intensity;
    // gl_FragColor = vs_out_color;
}
