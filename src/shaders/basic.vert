#version 130

attribute vec4 position;
attribute vec4 color;

uniform mat4 pr_matrix;
uniform mat4 vw_matrix = mat4(1.0);
uniform mat4 ml_matrix = mat4(1.0);

out vec4 vs_out_position;
out vec4 vs_out_color;

void main() {

      gl_Position = pr_matrix * vw_matrix * ml_matrix * position;
      vs_out_position = ml_matrix * position;
      vs_out_color = color;
}
