#include "vec2.hpp"

namespace myMath {

// TODO: Figure out how to do vec_1 += vec_2 + vec_3 without adta of vec+vec geting currupted (use vec_1 = vec_1 + vec_2 + vec_3)

// Default Constructor
vec2::vec2(){
}

// Overload constructor
vec2::vec2(const float& x, const float& y){
        this->x = x;
        this->y = y;
}

// Add 2 vectors
vec2& vec2::add(const vec2& other){
        x+= other.x;
        y+= other.y;
        return *this;
}

// Subtract 2 vectors
vec2& vec2::subtract(const vec2& other){
        x-= other.x;
        y-= other.y;
        return *this;
}

// Multiply 2 vectors
vec2& vec2::multiply(const vec2& other){
        x*= other.x;
        y*= other.y;
        return *this;
}

// Divide 2 vectors
vec2& vec2::divide(const vec2& other){
        x/= other.x;
        y/= other.y;
        return *this;
}

// These operators do not modify any of the data and just return the answer
// Plus operator
vec2 operator+(vec2 left,const vec2& right){
        return left.add(right);
}
// Subtract operator
vec2 operator-(vec2 left,const vec2& right){
        return left.subtract(right);
}
// Multiply operator
vec2 operator*(vec2 left,const vec2& right){
        return left.multiply(right);
}
// Divide operator
vec2 operator/(vec2 left,const vec2& right){
        return left.divide(right);
}

// These modifyers modify the data of the left parameter
// += operator
vec2& operator+=(vec2& left, const vec2& right){
        return left.add(right);
}
// -= operator
vec2& operator-=(vec2& left, const vec2& right){
        return left.subtract(right);
}
// *= operator
vec2& operator*=(vec2& left, const vec2& right){
        return left.multiply(right);
}
// /= operator
vec2& operator/=(vec2& left, const vec2& right){
        return left.divide(right);
}

// For comparing two vectors to see if they are equal
bool operator==(const vec2& left,const vec2& right){
        return (left.x == right.x && left.y == right.y);
}

// For comparing two vectors to see if they are not equal
bool operator!=(const vec2& left,const vec2& right){
        return (left.x != right.x && left.y != right.y);
}

// Allow for std::cout << vec2
std::ostream& operator<<(std::ostream& stream,const vec2& vector){
        stream << "vec2:(" << vector.x << "," << vector.y << ")";
        return stream;
}


}
