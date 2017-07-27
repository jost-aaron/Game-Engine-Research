#include "vec4.hpp"

namespace myMath {

// TODO: Figure out how to do vec_1 += vec_2 + vec_3 without adta of vec+vec geting currupted (use vec_1 = vec_1 + vec_2 + vec_3)

// Overload constructor
vec4::vec4(const float& x, const float& y,const float& z,const float& w){
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
}

// Add 2 vectors
vec4& vec4::add(const vec4& other){
        x+= other.x;
        y+= other.y;
        z+= other.z;
        w+= other.w;
        return *this;
}

// Subtract 2 vectors
vec4& vec4::subtract(const vec4& other){
        x-= other.x;
        y-= other.y;
        z-= other.z;
        w-= other.w;
        return *this;
}

// Multiply 2 vectors
vec4& vec4::multiply(const vec4& other){
        x*= other.x;
        y*= other.y;
        z*= other.z;
        w*= other.w;
        return *this;
}

// Divide 2 vectors
vec4& vec4::divide(const vec4& other){
        x/= other.x;
        y/= other.y;
        z/= other.z;
        w/= other.w;
        return *this;
}


// These operators do not modify any of the data and just return the answer
// Plus operator
vec4 operator+(vec4 left,const vec4& right){
        return left.add(right);
}
// Subtract operator
vec4 operator-(vec4 left,const vec4& right){
        return left.subtract(right);
}
// Multiply operator
vec4 operator*(vec4 left,const vec4& right){
        return left.multiply(right);
}
// Divide operator
vec4 operator/(vec4 left,const vec4& right){
        return left.divide(right);
}

// These modifyers modify the data of the left parameter
// += operator
vec4& operator+=(vec4& left, const vec4& right){
        return left = left.add(right);
}
// -= operator
vec4& operator-=(vec4& left, const vec4& right){
        return left.subtract(right);
}
// *= operator
vec4& operator*=(vec4& left, const vec4& right){
        return left.multiply(right);
}
// /= operator
vec4& operator/=(vec4& left, const vec4& right){
        return left.divide(right);
}

// For comparing two vectors to see if they are equal
bool operator==(const vec4& left,const vec4& right){
        return (left.x == right.x && left.y == right.y && left.z == right.z && left.w == right.w);
}

// For comparing two vectors to see if they are not equal
bool operator!=(const vec4& left,const vec4& right){
        return (left.x != right.x && left.y != right.y && left.z != right.z && left.w != right.w);
}

// Allow for std::cout << vec4
std::ostream& operator<<(std::ostream& stream,const vec4& vector){
        stream << "vec4:(" << vector.x << "," << vector.y << "," << vector.z <<"," << vector.w << ")";
        return stream;
}


}
