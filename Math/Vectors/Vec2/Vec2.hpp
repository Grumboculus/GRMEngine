#ifndef VEC2_HPP
#define VEC2_HPP

namespace engine {
namespace math {

/**
 * @brief Represents a 2D mathematical vector.
 */
class Vec2 {
    private:
        float x, y, magnitude; // x and y components, along with magnitude

    public:
        /**
         * @brief Default constructor. Initializes vector to (0, 0).
         */
        Vec2();

        /**
         * @brief Constructs a 2D vector with initial X and Y values.
         * 
         * @param xVal Initial X value.
         * @param yVal Initial Y value.
         */
        Vec2(float xVal, float yVal);

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
         * @brief Sets both X and Y components.
         * @param xVal The new X value.
         * @param yVal The new Y value.
         */
        void Set(float xVal, float yVal);

        /**
         * @brief Returns the normalized version of this vector (magnitude of 1).
         * @return Vec2 The normalized vector.
         */
        Vec2 Normalize() const;

        /**
         * @brief Calculates and returns the length (magnitude) of the vector.
         * @return float The length of the vector.
         */
        float Length() const;

        /**
         * @brief Adds another vector to this vector.
         * @param other The vector to add.
         * @return Vec2 The resulting vector.
         */
        Vec2 operator+(const Vec2& other) const;

        /**
         * @brief Subtracts another vector from this vector.
         * @param other The vector to subtract.
         * @return Vec2 The resulting vector.
         */
        Vec2 operator-(const Vec2& other) const;
    };

}
}

#endif