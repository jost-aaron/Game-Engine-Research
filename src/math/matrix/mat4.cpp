#include "mat4.hpp"
#include <math.h>


namespace myMath {

// Default Constructor with all elements 0
mat4::mat4(){
        for (int i=0; i< 4*4; i++) {
                elements[i] = 0.0f;
        }
}

// Create an matrix with all zeros but diagonal number on the diagonals
mat4::mat4(float diagonalNumber){
        for (int i=0; i< 4*4; i++) {
                elements[i] = 0.0f;
        }

        modify(0,0,diagonalNumber);
        modify(1,1,diagonalNumber);
        modify(2,2,diagonalNumber);
        modify(3,3,diagonalNumber);
}

// modify a value in the matrix
void mat4::modify(int row,int colum,float value){
        elements[row + colum*4] = value;
}

// Get the value at the index
float mat4::access(int row, int colum){
        return elements[row + colum*4];
}

// Generate an identity matrix
mat4 mat4::identity(){
        return mat4(1.0f);
}

// multiply two matrix
mat4& mat4::multiply(const mat4& other){

        float data[16];

        for (size_t y = 0; y < 4; y++) {
                for (size_t x = 0; x < 4; x++) {

                        float sum = 0.0f;
                        for (size_t e = 0; e < 4; e++) {
                                sum += elements[x + e*4]*other.elements[e + y*4];
                        }
                        data[x+y*4] = sum;
                }
        }

        memcpy(elements,data,4*4*sizeof(float));

        return *this;
}

// Multiply a matrix by a vec3
vec3 mat4::multiply(const vec3& other) const {

        return vec3(
                column[0].x * other.x + column[1].x * other.y + column[2].x * other.z + column[3].x,
                column[0].y * other.y + column[1].y * other.y + column[2].y * other.z + column[3].y,
                column[0].z * other.z + column[1].z * other.y + column[2].z * other.z + column[3].z
                );
}

// Multiply a matrix by a vec4
vec4 mat4::multiply(const vec4& other) const {

        return vec4(
                column[0].x * other.x + column[1].x * other.y + column[2].x * other.z + column[3].x * other.w,
                column[0].y * other.y + column[1].y * other.y + column[2].y * other.z + column[3].y * other.w,
                column[0].z * other.z + column[1].z * other.y + column[2].z * other.z + column[3].z * other.w,
                column[0].w * other.w + column[1].w * other.y + column[2].w * other.z + column[3].w * other.w
                );
}

mat4 operator*(mat4 left, const mat4& right){
        return left.multiply(right);
}

mat4& mat4::operator*=(const mat4& other){
        return multiply(other);
}


vec3 operator*(const mat4& left, const vec3& right){
        return left.multiply(right);
}

vec4 operator*(const mat4& left, const vec4& right){
        return left.multiply(right);
}



mat4 mat4::orthographic(float left,float right,float bottom,float top,float near,float far){
        mat4 result(1.0f);

        result.modify(0,0,2.0f/(right-left));
        result.modify(1,1,2.0f/(top-bottom));
        result.modify(2,2,-2.0f/(near-far));
        result.modify(0,3,(left+right)/(left-right));
        result.modify(1,3,(bottom + top)/(bottom-top));
        result.modify(2,3,(far+near)/(far-near));

        return result;
}

// mat4 mat4::orthographic(float left, float right, float bottom, float top, float near, float far)
//  {
//    mat4 result(1.0f);
//
//    result.elements[0 + 0 * 4] = 2.0f / (right - left);
//
//    result.elements[1 + 1 * 4] = 2.0f / (top - bottom);
//
//    result.elements[2 + 2 * 4] = 2.0f / (near - far);
//
//    result.elements[3 + 0 * 4] = (left + right) / (left - right);
//    result.elements[3 + 1 * 4] = (bottom + top) / (bottom - top);
//    result.elements[3 + 2 * 4] = (far + near) / (far - near);
//
//    return result;
//  }

mat4 mat4::perspective(float fov,float aspectRatio,float near,float far){
        mat4 result(0.0f);

        float q = 1.0f / tan(0.5*fov*(3.1415926535897 / 180.0f));
        float a = q / aspectRatio;

        result.modify(0,0,a);
        result.modify(1,1,q);
        result.modify(2,2,(near+far)/(near-far));
        result.modify(2,3,(2.0f*far*near)/(near-far));
        result.modify(3,2,1.0f);

        return result;
}

// Generate a transloation matrix
mat4 mat4::translation(const vec3& translation){
        mat4 result(1.0f);

        result.modify(0,3,translation.x);
        result.modify(1,3,translation.y);
        result.modify(2,3,translation.z);

        return result;
}

#if 1

mat4 mat4::rotation(float angle, const vec3& axis){
        mat4 result(1.0f);

        float r = angle*(3.1415926535897f / 180.0f);
        float c = cos(r);
        float s = sin(r);
        float omc = 1.0f - c;

        float x = axis.x;
        float y = axis.y;
        float z = axis.z;

        result.elements[0 + 0 * 4] = x * omc + c;
        result.elements[0 + 1 * 4] = -(y * x * omc + z * s);
        result.elements[0 + 2 * 4] = x * z * omc - y * s;

        result.elements[1 + 0 * 4] = -(x * y * omc - z * s);
        result.elements[1 + 1 * 4] = (y * omc + c);
        result.elements[1 + 2 * 4] = y * z * omc + x * s;

        result.elements[2 + 0 * 4] = x * z * omc + y * s;
        result.elements[2 + 1 * 4] = y * z * omc - x * s;
        result.elements[2 + 2 * 4] = z * omc + c;

        return result;
}

#else
mat4 mat4::rotation(float angle, const vec3& axis){
        mat4 result(1.0f);

        float a_rads = angle*(3.1415926535897f / 180.0f);
        float a_cos = cos(a_rads);
        float a_sin = sin(a_rads);

        float omc = 1.0f-a_cos;

        float x = axis.x;
        float y = axis.y;
        float z = axis.z;


        // Column 0
        result.modify(0,0,x*omc + a_cos);
        result.modify(1,0,x*y*omc+z*a_sin);
        result.modify(2,0,x*z*omc-y*a_sin);

        // Column 1
        result.modify(0,1,x * y * omc - z * a_sin);
        result.modify(1,1,y * y * omc + a_cos);
        result.modify(2,1,y * z * omc + x * a_sin);

        // Column 2
        result.modify(0,2,x * z * omc + y * a_sin);
        result.modify(1,2,y * z * omc - x * a_sin);
        result.modify(2,2,z * z * omc + a_cos);


        return result;
}

#endif

// Generate a scalse matrix for the following scale vector
mat4 mat4::scale(const vec3& scale){
        mat4 result(1.0f);
        result.modify(0,0,scale.x);
        result.modify(1,1,scale.y);
        result.modify(2,2,scale.z);

        return result;
}

// Allow for std::cout << mat4
std::ostream& operator<<(std::ostream& stream,mat4& matrix) {
        stream << "mat4:\n";
        for (int row = 0; row < 4; row++) {
                stream << "   | ";
                for (int colum = 0; colum < 4; colum++) {
                        stream << " " << std::to_string(matrix.access(row,colum)) << " ";
                }
                stream << " |\n";
        }
        return stream;
}


}
