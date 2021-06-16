
# Time Complexities

## Mat4[fd]

- `Mat4 Mat4::operator*(const Mat4& mat)` -- `O(112)`
- `Vec4 Mat4::operator*(const Vec4& vec)` -- `O(28)`
- `Mat4 Mat4::inverse()` -- `O(128)`
- `Vec3 Mat4::affineInvert(const Vec3& vec3)` -- `O(71)`

## Mat3[fd]

- `Mat3 Mat3::operator*(const Mat3& mat)` -- `O(12)`
- `Mat3 Mat3::operator/(const Mat3& mat)` -- `O(74)`
- `bool Mat3::isInvertible()` -- `O(19)`
- `float Mat3::determinant()` -- `O(14)`
- `Mat3 Mat3::minorDet()` -- `O(27)`
- `Mat3 Mat3::inverse()` -- `O(51)`
