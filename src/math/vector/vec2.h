#pragma once
#include <iostream>

namespace myMath {

// 2D vector struct
struct vec2 {

        // Member variables
        float x,y;

        // constructor prototypes
        vec2();
        vec2(const float& x, const float& y);

        // Basic math prototypes
        vec2& add(const vec2&);
        vec2& subtract(const vec2&);
        vec2& multiply(const vec2&);
        vec2& divide(const vec2&);

        // operator friend function prototypes
        friend vec2 operator+(vec2,const vec2&);
        friend vec2 operator-(vec2,const vec2&);
        friend vec2 operator*(vec2,const vec2&);
        friend vec2 operator/(vec2,const vec2&);

        // operator= friend function prototypes
        friend vec2& operator+=(vec2&,const vec2&);
        friend vec2& operator-=(vec2&,const vec2&);
        friend vec2& operator*=(vec2&,const vec2&);
        friend vec2& operator/=(vec2&,const vec2&);

        friend bool operator==(const vec2& left,const vec2& right);
        friend bool operator!=(const vec2& left,const vec2& right);

        // For printing to console
        friend std ::ostream& operator<<(std::ostream&,const vec2&);


};

}
