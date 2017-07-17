#include "vec3.h"

namespace myMath {

// TODO: Figure out how to do vec_1 += vec_2 + vec_3 without adta of vec+vec geting currupted (use vec_1 = vec_1 + vec_2 + vec_3)

// Default Constructor
vec3::vec3(){
}

// Overload constructor
vec3::vec3(const float& x, const float& y,const float& z){
        this->x = x;
        this->y = y;
        this->z = z;
}

// Add 2 vectors
vec3& vec3::add(const vec3& other){
        x+= other.x;
        y+= other.y;
        z+= other.z;
        return *this;
}

// Subtract 2 vectors
vec3& vec3::subtract(const vec3& other){
        x-= other.x;
        y-= other.y;
        z-= other.z;
        return *this;
}

// Multiply 2 vectors
vec3& vec3::multiply(const vec3& other){
        x*= other.x;
        y*= other.y;
        z*= other.z;
        return *this;
}

// Divide 2 vectors
vec3& vec3::divide(const vec3& other){
        x/= other.x;
        y/= other.y;
        z/= other.z;
        return *this;
}

// These operators do not modify any of the data and just return the answer
// Plus operator
vec3 operator+(vec3 left,const vec3& right){
        return left.add(right);
}
// Subtract operator
vec3 operator-(vec3 left,const vec3& right){
        return left.subtract(right);
}
// Multiply operator
vec3 operator*(vec3 left,const vec3& right){
        return left.multiply(right);
}
// Divide operator
vec3 operator/(vec3 left,const vec3& right){
        return left.divide(right);
}

// These modifyers modify the data of the left parameter
// += operator
vec3& operator+=(vec3& left, const vec3& right){
        return left = left.add(right);
}
// -= operator
vec3& operator-=(vec3& left, const vec3& right){
        return left.subtract(right);
}
// *= operator
vec3& operator*=(vec3& left, const vec3& right){
        return left.multiply(right);
}
// /= operator
vec3& operator/=(vec3& left, const vec3& right){
        return left.divide(right);
}

// For comparing two vectors to see if they are equal
bool operator==(const vec3& left,const vec3& right){
        return (left.x == right.x && left.y == right.y && left.z == right.z);
}

// For comparing two vectors to see if they are not equal
bool operator!=(const vec3& left,const vec3& right){
        return (left.x != right.x && left.y != right.y && left.z != right.z);
}

// Allow for std::cout << vec3
std::ostream& operator<<(std::ostream& stream,const vec3& vector){
        stream << "vec3:(" << vector.x << "," << vector.y << "," << vector.z <<  ")";
        return stream;
}


}
