#include "mat4.h"
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

        for (size_t y = 0; y < 4; y++) {
                for (size_t x = 0; x < 4; x++) {

                        float sum = 0.0f;
                        for (size_t e = 0; e < 4; e++) {
                                sum += elements[x + e*4]*other.elements[e + y*4];
                        }
                        elements[x+y*4] = sum;
                }
        }

        return *this;
}

mat4 operator*(mat4 left, const mat4& right){
        return left.multiply(right);
}

mat4& mat4::operator*=(const mat4& other){
        return multiply(other);
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
// 	{
// 		mat4 result(1.0f);
//
// 		result.elements[0 + 0 * 4] = 2.0f / (right - left);
//
// 		result.elements[1 + 1 * 4] = 2.0f / (top - bottom);
//
// 		result.elements[2 + 2 * 4] = 2.0f / (near - far);
//
// 		result.elements[3 + 0 * 4] = (left + right) / (left - right);
// 		result.elements[3 + 1 * 4] = (bottom + top) / (bottom - top);
// 		result.elements[3 + 2 * 4] = (far + near) / (far - near);
//
// 		return result;
// 	}

mat4 mat4::perspective(float fov,float aspectRatio,float near,float far){
        mat4 result(0.0f);

        float q = 1.0f / tan(toRadians(0.5*fov));
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

mat4 mat4::rotation(float angle, const vec3& axis){
        mat4 result(1.0f);

        float a_rads = toRadians(angle);
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
