
//------------ VERSION 130 Shader -----------------
// #version 130
// attribute vec4 position;
// attribute vec4 color;
//
// uniform mat4 pr_matrix;
// uniform mat4 vw_matrix = mat4(1.0);
// uniform mat4 ml_matrix = mat4(1.0);
//
// out vec4 vs_out_position;
// out vec4 vs_out_color;
//
// void main() {
//
//       gl_Position = pr_matrix * vw_matrix * ml_matrix * position;
//       vs_out_position = ml_matrix * position;
//       vs_out_color = color;
// }


//------------ VERSION 330 Shader -----------------
#version 330

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 color;

uniform mat4 pr_matrix;
uniform mat4 vw_matrix = mat4(1.0);
uniform mat4 ml_matrix = mat4(1.0);

out DATA {
  vec4 position;
  vec4 color;
} vs_out;

void main() {

      gl_Position = pr_matrix * vw_matrix * ml_matrix * position;
      vs_out.position = ml_matrix * position;
      vs_out.color = color;
}
