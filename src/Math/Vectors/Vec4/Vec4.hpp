#ifndef VEC4_HPP
#define VEC4_HPP

namespace engine {
namespace math {
    
    /**
     * @brief Represents a 4D mathematical vector.
     */
    class Vec4 {
        private:
            float x, y, z, w; // x, y, z, and w components

        public:
            /**
             * @brief Default constructor. Initializes vector to (0, 0, 0, 1).
             */
            Vec4();

            /**
             * @brief Constructs a 4D vector with initial values.
             * 
             * @param xVal Initial X value.
             * @param yVal Initial Y value.
             * @param zVal Initial Z value.
             * @param wVal Initial W value.
             */
            Vec4(float xVal, float yVal, float zVal, float wVal);

            /**
             * @brief Gets the X component.
             * @return float The X component.
             */
            float GetX() const;

            /**
             * @brief Gets the Y component.
             * @return float The Y component.
             */
            float GetY() const;

            /**
             * @brief Gets the Z component.
             * @return float The Z component.
             */
            float GetZ() const;

            /**
             * @brief Gets the W component.
             * @return float The W component.
             */
            float GetW() const;

            /**
             * @brief Sets the X component.
             * @param xVal The new X value.
             */
            void SetX(float xVal);

            /**
             * @brief Sets the Y component.
             * @param yVal The new Y value.
             */
            void SetY(float yVal);

            /**
             * @brief Sets the Z component.
             * @param zVal The new Z value.
             */
            void SetZ(float zVal);

            /**
             * @brief Sets the W component.
             * @param wVal The new W value.
             */
            void SetW(float wVal);

            /**
             * @brief Adds another vector to this vector.
             * @param other The vector to add.
             * @return Vec4 The resulting vector.
             */
            Vec4 operator+(const Vec4& other) const;

            /**
             * @brief Subtracts another vector from this vector.
             * @param other The vector to subtract.
             * @return Vec4 The resulting vector.
             */
            Vec4 operator-(const Vec4& other) const;
    };

}
}

#endif