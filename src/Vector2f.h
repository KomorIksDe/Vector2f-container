#ifndef VECTOR2F_H_INCLUDED
#define VECTOR2F_H_INCLUDED

#include <cmath>

namespace kr {
    class Vector2f {
        private:
            float posX;
            float posY;
            float distFrom00;

        public:
            Vector2f(float x, float y)
            :   posX(x), posY(y) {
                this->distFrom00 = sqrt(pow(posX, 2) + pow(posY, 2));
            }

            Vector2f(float& x, float& y)
            :   posX(x), posY(y) {
                this->distFrom00 = sqrt(pow(posX, 2) + pow(posY, 2));
            }

            Vector2f(const Vector2f& other) {
                *this = other;
            }

            Vector2f& operator= (const Vector2f& other) {
                this->posX = other.getPosX();
                this->posY = other.getPosY();

                return *this;
            }

            float getPosX() const {
                return this->posX;
            }

            float getPosY() const {
                return this->posY;
            }

            float getVector() const {
                return this->distFrom00;
            }

            void setX(float value) {
                this->posX = value;
            }

            void setY(float value) {
                this->posY = value;
            }

            bool operator!= (const Vector2f& other) {
                return (this->posX != other.getPosX() || this->posY != other.getPosY());
            }

            bool operator== (const Vector2f& other) {
                return (this->posX == other.getPosX() && this->posY == other.getPosY());
            }

            bool operator> (const Vector2f& other) {
                return (this->distFrom00 > other.getVector());
            }

            bool operator< (const Vector2f& other) {
                return (this->distFrom00 < other.getVector());
            }

            bool operator>= (const Vector2f& other) {
                return (this->distFrom00 >= other.getVector());
            }

            bool operator<= (const Vector2f& other) {
                return (this->distFrom00 <= other.getVector());
            }
    };
}

#endif // VECTOR2F_H_INCLUDED
