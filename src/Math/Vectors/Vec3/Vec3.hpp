#ifndef VEC3_HPP
#define VEC3_HPP

namespace engine {
namespace math {

    /**
     * @brief Represents a 3D mathematical vector.
     */
    class Vec3 {
        private: 
            float x, y, z; // x, y, and z components
        public: 
            /**
             * @brief Default constructor. Initializes vector to (0, 0, 0).
             */
            Vec3();

            /**
             * @brief Constructs a 3D vector with initial values.
             * 
             * @param xVal Initial X value.
             * @param yVal Initial Y value.
             * @param zVal Initial Z value.
             */
            Vec3(float xVal, float yVal, float zVal);

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
             * @brief Sets all components simultaneously.
             * @param xVal The new X value.
             * @param yVal The new Y value.
             * @param zVal The new Z value.
             */
            void Set(float xVal, float yVal, float zVal);

            /**
             * @brief Calculates and returns the length (magnitude) of the vector.
             * @return float The length of the vector.
             */
            float Length() const;

            /**
             * @brief Returns a normalized copy of this vector (magnitude of 1).
             * @return Vec3 The normalized vector.
             */
            Vec3 Normalized() const;

            /**
             * @brief Calculates the dot product with another vector.
             * @param other The vector to dot product with.
             * @return float The dot product result.
             */
            float Dot(const Vec3& other) const;

            /**
             * @brief Adds another vector to this vector.
             * @param other The vector to add.
             * @return Vec3 The resulting vector.
             */
            Vec3 operator+(const Vec3& other) const;
    };

}
}

#endif