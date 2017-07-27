#pragma once
#include <iostream>

namespace myMath {

// 2D vector struct
struct vec3 {

        // Member variables
        float x,y,z;

        // constructor prototypes
        vec3();
        vec3(const float& x, const float& y,const float& z);

        // Basic math prototypes
        vec3& add(const vec3&);
        vec3& subtract(const vec3&);
        vec3& multiply(const vec3&);
        vec3& divide(const vec3&);

        // operator friend function prototypes
        friend vec3 operator+(vec3,const vec3&);
        friend vec3 operator-(vec3,const vec3&);
        friend vec3 operator*(vec3,const vec3&);
        friend vec3 operator/(vec3,const vec3&);

        // operator= friend function prototypes
        friend vec3& operator+=(vec3&,const vec3&);
        friend vec3& operator-=(vec3&,const vec3&);
        friend vec3& operator*=(vec3&,const vec3&);
        friend vec3& operator/=(vec3&,const vec3&);

        friend bool operator==(const vec3& left,const vec3& right);
        friend bool operator!=(const vec3& left,const vec3& right);

        // For printing to console
        friend std ::ostream& operator<<(std::ostream&,const vec3&);


};

}
