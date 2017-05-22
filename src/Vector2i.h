#ifndef VECTOR2I_H_INCLUDED
#define VECTOR2I_H_INCLUDED

#include <cmath>

namespace kr {
    class Vector2i {
        private:
            int posX;
            int posY;
            int distFrom00;

        public:
            Vector2i(int x, int y)
            :   posX(x), posY(y) {
                this->distFrom00 = sqrt(pow(posX, 2) + pow(posY, 2));
            }

            Vector2i(int& x, int& y)
            :   posX(x), posY(y) {
                this->distFrom00 = sqrt(pow(posX, 2) + pow(posY, 2));
            }

            Vector2i(const Vector2i& other) {
                *this = other;
            }

            Vector2i& operator= (const Vector2i& other) {
                this->posX = other.getPosX();
                this->posY = other.getPosY();

                return *this;
            }

            int getPosX() const {
                return this->posX;
            }

            int getPosY() const {
                return this->posY;
            }

            int getVector() const {
                return this->distFrom00;
            }

            void setX(int value) {
                this->posX = value;
            }

            void setY(int value) {
                this->posY = value;
            }

            bool operator!= (const Vector2i& other) {
                return (this->posX != other.getPosX() || this->posY != other.getPosY());
            }

            bool operator== (const Vector2i& other) {
                return (this->posX == other.getPosX() && this->posY == other.getPosY());
            }

            bool operator> (const Vector2i& other) {
                return (this->distFrom00 > other.getVector());
            }

            bool operator< (const Vector2i& other) {
                return (this->distFrom00 < other.getVector());
            }

            bool operator>= (const Vector2i& other) {
                return (this->distFrom00 >= other.getVector());
            }

            bool operator<= (const Vector2i& other) {
                return (this->distFrom00 <= other.getVector());
            }
    };
}

#endif // VECTOR2I_H_INCLUDED
