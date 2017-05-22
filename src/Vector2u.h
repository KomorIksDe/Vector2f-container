#ifndef VECTOR2U_H_INCLUDED
#define VECTOR2U_H_INCLUDED

#include <cmath>

namespace kr {
    class Vector2u {
        private:
            unsigned posX;
            unsigned posY;
            unsigned distFrom00;

        public:
            Vector2u(unsigned x, unsigned y)
            :   posX(x), posY(y) {
                this->distFrom00 = sqrt(pow(posX, 2) + pow(posY, 2));
            }

            Vector2u(unsigned& x, unsigned& y)
            :   posX(x), posY(y) {
                this->distFrom00 = sqrt(pow(posX, 2) + pow(posY, 2));
            }

            Vector2u(const Vector2u& other) {
                *this = other;
            }

            Vector2u& operator= (const Vector2u& other) {
                this->posX = other.getPosX();
                this->posY = other.getPosY();

                return *this;
            }

            unsigned getPosX() const {
                return this->posX;
            }

            unsigned getPosY() const {
                return this->posY;
            }

            unsigned getVector() const {
                return this->distFrom00;
            }

            void setX(unsigned value) {
                this->posX = value;
            }

            void setY(unsigned value) {
                this->posY = value;
            }

            bool operator!= (const Vector2u& other) {
                return (this->posX != other.getPosX() || this->posY != other.getPosY());
            }

            bool operator== (const Vector2u& other) {
                return (this->posX == other.getPosX() && this->posY == other.getPosY());
            }

            bool operator> (const Vector2u& other) {
                return (this->distFrom00 > other.getVector());
            }

            bool operator< (const Vector2u& other) {
                return (this->distFrom00 < other.getVector());
            }

            bool operator>= (const Vector2u& other) {
                return (this->distFrom00 >= other.getVector());
            }

            bool operator<= (const Vector2u& other) {
                return (this->distFrom00 <= other.getVector());
            }
    };
}

#endif // VECTOR2U_H_INCLUDED
