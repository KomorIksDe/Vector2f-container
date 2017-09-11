#ifndef VECTOR2_HPP_INCLUDED
#define VECTOR2_HPP_INCLUDED

#include <cmath>

template<typename T>
class Vector2 {
    public:
        T x            = 0;
        T y            = 0;
        float toOrigin = 0;

    public:
        Vector2(T _x, T _y)
        :   x(_x)
        ,   y(_y)
        ,   toOrigin(sqrt( pow(x, 2)) + pow(y, 2) )
        { }

        Vector2(const Vector2& other) {
            *this = other;
        }

        Vector2(Vector2&& other) {
            *this = std::move(other);
        }

        Vector2& operator= (const Vector2& other) {
            x        = other.x;
            y        = other.y;
            toOrigin = other.toOrigin;

            return *this;
        }

        Vector2& operator= (Vector2&& other) {
            x        = other.x;
            y        = other.y;
            toOrigin = other.toOrigin;

            other.x        = 0;
            other.y        = 0;
            other.toOrigin = 0;

            return *this;
        }

        bool operator== (const Vector2& other) {
            return ((toOrigin == other.toOrigin) && (x == other.x) && (y == other.y));
        }

        bool operator!= (const Vector2& other) {
            return ((toOrigin != other.toOrigin) && (x != other.x) && (y != other.y));
        }

        bool operator<  (const Vector2& other) {
            return toOrigin < other.toOrigin;
        }

        bool operator<= (const Vector2& other) {
            return toOrigin <= other.toOrigin;
        }

        bool operator>  (const Vector2& other) {
            return toOrigin > other.toOrigin;
        }

        bool operator>= (const Vector2& other) {
            return toOrigin >= other.toOrigin;
        }
};

#endif // VECTOR2_HPP_INCLUDED
