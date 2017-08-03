#pragma once
// #include "../toRadians.hpp"
#include "../vector/vec2.hpp"
#include "../vector/vec3.hpp"
#include "../vector/vec4.hpp"
#include <cstring>

namespace myMath {


struct mat4 {

        // inline float toRadians(float degrees){
        //         return degrees*(3.1415926535897 / 180.0f);
        // }


        // This allows for accessing individual collums of the matrix as a refferenced version without making a new one
        union {
                // Array to store all of the elements in the matrix
                float elements[4 * 4];
                vec4 column[4];
        };
        // Default Constructor
        mat4();

        // Multiply two matricies
        mat4& multiply(const mat4& other);
        friend mat4 operator*(mat4 left, const mat4& right);

        // Multiply a matrix by a vec3
        vec3 multiply(const vec3& other) const;
        friend vec3 operator*(const mat4& left, const vec3& right);

        // Multiply a matrix by a vec4
        vec4 multiply(const vec4& other) const;
        friend vec4 operator*(const mat4& left, const vec4& right);

        mat4& operator*=(const mat4& other);

        float access(int,int);
        void modify(int row,int colum,float value);

        // Generate different matricies
        mat4(float diagonalNumber);
        static mat4 identity();
        static mat4 orthographic(float left,float right,float bottom,float top,float near,float far);
        static mat4 perspective(float fov,float aspectRatio,float near,float far);
        static mat4 translation(const vec3& translation);
        static mat4 rotation(float angle, const vec3& axis);
        static mat4 scale(const vec3& scale);


        friend std ::ostream& operator<<(std::ostream& stream,mat4& matrix);

};



}
