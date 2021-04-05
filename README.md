# axl.math

A simple C++ math library primarily designed for game engines.

## Versions

- Latest: 0.27.28 beta

## library headers

- [`axl.math/everything.hpp`](/include/axl.math/everything.hpp) - Includes every header in the library.
- [`axl.math/lib.hpp`](/include/axl.math/lib.hpp) - *Library main header. Contains ***version***, ***library type*** and ***build type***.*
- [`axl.math/angle.hpp`](/include/axl.math/angle.hpp) - *Angle conversion functions.*
- [`axl.math/basic.hpp`](/include/axl.math/basic.hpp) - *Basic mathematical functions.*
- [`axl.math/constants.hpp`](/include/axl.math/constants.hpp) - *Mathematical constants like Pi, e, ...*
- [`axl.math/rules.hpp`](/include/axl.math/rules.hpp) - *Mathematical rules such as axis orientation, ...*
- [`axl.math/double.hpp`](/include/axl.math/double.hpp) - *Double floating point number comparison and checking functions.*
- [`axl.math/float.hpp`](/include/axl.math/float.hpp) - *Single floating point number comparison and checking functions.*
- [`axl.math/util.hpp`](/include/axl.math/util.hpp) - *Utility functions.*
- [`axl.math/vec.hpp`](/include/axl.math/vec.hpp) - *Includes all header files under **vec**.*
- [`axl.math/mat.hpp`](/include/axl.math/mat.hpp) - *Includes all header files under **mat**.*
- [`axl.math/rectangle.hpp`](/include/axl.math/rectangle.hpp) - *Includes all header files under **rectangle**.*
- **Vectors**
  - [`axl.math/vec/Vec2i.hpp`](/include/axl.math/vec/Vec2i.hpp) - *A 2D integer vector.*
  - [`axl.math/vec/Vec2f.hpp`](/include/axl.math/vec/Vec2f.hpp) - *A 2D single precision floating point vector.*
  - [`axl.math/vec/Vec2d.hpp`](/include/axl.math/vec/Vec2d.hpp) - *A 2D double precision floating point vector.*
  - [`axl.math/vec/Vec2.hpp`](/include/axl.math/vec/Vec2.hpp) - *A 2D template vector.*
  - [`axl.math/vec/Vec3f.hpp`](/include/axl.math/vec/Vec3f.hpp) - *A 3D single precision floating point vector.*
  - [`axl.math/vec/Vec3d.hpp`](/include/axl.math/vec/Vec3d.hpp) - *A 3D double precision floating point vector.*
  - [`axl.math/vec/Vec3.hpp`](/include/axl.math/vec/Vec3.hpp) - *A 3D template vector.*
  - [`axl.math/vec/Vec4f.hpp`](/include/axl.math/vec/Vec4f.hpp) - *A 4D single precision floating point vector.*
  - [`axl.math/vec/Vec4d.hpp`](/include/axl.math/vec/Vec4d.hpp) - *A 4D double precision floating point vector.*
  - [`axl.math/vec/Vec4.hpp`](/include/axl.math/vec/Vec4.hpp) - *A 4D template vector.*
- **Matrices**
  - [`axl.math/mat/Mat2f.hpp`](/include/axl.math/mat/Mat2f.hpp) - *A 2x2 single precision floating point matrix.*
  - [`axl.math/mat/Mat2d.hpp`](/include/axl.math/mat/Mat2d.hpp) - *A 2x2 double precision floating point matrix.*
  - [`axl.math/mat/Mat3f.hpp`](/include/axl.math/mat/Mat3f.hpp) - *A 3x3 single precision floating point matrix.*
  - [`axl.math/mat/Mat3d.hpp`](/include/axl.math/mat/Mat3d.hpp) - *A 3x3 double precision floating point matrix.*
  - [`axl.math/mat/Mat4f.hpp`](/include/axl.math/mat/Mat4f.hpp) - *A 4x4 single precision floating point matrix.*
  - [`axl.math/mat/Mat4d.hpp`](/include/axl.math/mat/Mat4d.hpp) - *A 4x4 double precision floating point matrix.*
  - [`axl.math/mat/transform2.hpp`](/include/axl.math/mat/transform2.hpp) - *Transforming functions that return a 2x2 transform matrix.*
  - [`axl.math/mat/transform3.hpp`](/include/axl.math/mat/transform3.hpp) - *Transforming functions that return a 3x3 transform matrix.*
  - [`axl.math/mat/transform4.hpp`](/include/axl.math/mat/transform4.hpp) - *Transforming functions that return a 4x4 transform matrix.*
- **Rectangles**
  - [`axl.math/rectangle/Rectanglei.hpp`](/include/axl.math/rectangle/Rectanglei.hpp) - *Integer Rectangle class.*
  - [`axl.math/rectangle/Rectangled.hpp`](/include/axl.math/rectangle/Rectangled.hpp) - *A double precision floating point Rectangle class.*
  - [`axl.math/rectangle/Rectanglef.hpp`](/include/axl.math/rectangle/Rectanglef.hpp) - *A single precision floating point Rectangle class.*

## Requirements

- CMake 3.4 or above.
- Any C and C++ SDK that can be accessed through a command line. (MSVC, MinGW) If you have Visual Studio or CodeBlocks then you are set.

## How to get started

- Clone this repo into a directory and execute these commands to build the library.
  - git clone https://github.com/defalt8/axl.math.git
  - cd axl.math
  - mkdir out\\build
  - cd out\\build
  - cmake -B . -S ../../ (or with a generator of your choosing.) cmake -G \<generator\> -B . -S ../../
  - cmake --build .

## CMake Options

Default values are marked **bold**.

- Library specific options
  - AXLMATH_TYPE=[**STATIC**|SHARED]
  - AXLMATH_BUILD_TESTS=[**ON**|OFF]
  - AXLMATH_BUILD_TOOLS=[**ON**|OFF]
  - AXLMATH_INSTALL_HEADERS=[**ON**|OFF]
  - AXLMATH_INSTALL_ARCHIVES=[**ON**|OFF]
  - AXLMATH_INSTALL_BINARIES=[**ON**|OFF]
- General options
  - BUILD_TESTS=[ON|**OFF**]
  - BUILD_TOOLS=[ON|**OFF**]
  - INSTALL_HEADERS=[**ON**|OFF]
  - INSTALL_ARCHIVES=[**ON**|OFF]
  - INSTALL_BINARIES=[**ON**|OFF]
