#ifndef VECTOR3_HPP_INCLUDED
#define VECTOR3_HPP_INCLUDED

#include <cmath>

template<typename T>
class Vector3 {
    public:
        T x            = 0;
        T y            = 0;
        T z            = 0;
        float toOrigin = 0;

    public:
        Vector3(T _x, T _y, T _z)
        :   x(_x)
        ,   y(_y)
        ,   z(_z)
        ,   toOrigin(sqrt( pow(x, 2) + pow(y, 2) + pow(z, 2) ))
        { }

        Vector3(const Vector3& other) {
            *this = other;
        }

        Vector3(Vector3&& other) {
            *this = std::move(other);
        }

        Vector3& operator= (const Vector3& other) {
            x        = other.x;
            y        = other.y;
            z        = other.z;
            toOrigin = other.toOrigin;

            return *this;
        }

        Vector3& operator= (Vector3&& other) {
            x        = other.x;
            y        = other.y;
            z        = other.z;
            toOrigin = other.toOrigin;

            other.x        = 0;
            other.y        = 0;
            other.z        = 0;
            other.toOrigin = 0;

            return *this;
        }

        bool operator== (const Vector3& other) {
            return ((toOrigin == other.toOrigin) && (x == other.x) && (y == other.y) && (z == other.z));
        }

        bool operator!= (const Vector3& other) {
            return ((toOrigin != other.toOrigin) && (x != other.x) && (y != other.y) && (z != other.z));
        }

        bool operator<  (const Vector3& other) {
            return toOrigin < other.toOrigin;
        }

        bool operator<= (const Vector3& other) {
            return toOrigin <= other.toOrigin;
        }

        bool operator>  (const Vector3& other) {
            return toOrigin > other.toOrigin;
        }

        bool operator>= (const Vector3& other) {
            return toOrigin >= other.toOrigin;
        }
};

#endif // VECTOR3_HPP_INCLUDED
