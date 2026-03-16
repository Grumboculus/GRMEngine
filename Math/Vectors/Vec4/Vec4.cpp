#include "Vec4.hpp"
using namespace engine::math;

Vec4::Vec4() : x(0.0f), y(0.0f), z(0.0f), w(1) {}

float Vec4::GetX() const { return x; }
float Vec4::GetY() const { return y; }
float Vec4::GetZ() const { return z; }
int Vec4::GetW() const { return w; }