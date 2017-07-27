#pragma once
#include <iostream>

namespace myMath {

// 2D vector struct
struct vec4 {

        // Member variables
        float x,y,z,w;

        // constructor prototypes
        vec4() = default;
        vec4(const float& x, const float& y,const float& z,const float& w);

        // Basic math prototypes
        vec4& add(const vec4&);
        vec4& subtract(const vec4&);
        vec4& multiply(const vec4&);
        vec4& divide(const vec4&);

        // operator friend function prototypes
        friend vec4 operator+(vec4,const vec4&);
        friend vec4 operator-(vec4,const vec4&);
        friend vec4 operator*(vec4,const vec4&);
        friend vec4 operator/(vec4,const vec4&);

        // operator= friend function prototypes
        friend vec4& operator+=(vec4&,const vec4&);
        friend vec4& operator-=(vec4&,const vec4&);
        friend vec4& operator*=(vec4&,const vec4&);
        friend vec4& operator/=(vec4&,const vec4&);

        friend bool operator==(const vec4& left,const vec4& right);
        friend bool operator!=(const vec4& left,const vec4& right);

        // For printing to console
        friend std ::ostream& operator<<(std::ostream&,const vec4&);


};

}
