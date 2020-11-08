cmake_minimum_required( VERSION 3.17 )

link_libraries( axl.math )

add_executable( lib lib.cpp )
add_executable( double double.cpp )
add_executable( float float.cpp )
add_executable( angle angle.cpp )
add_executable( Vec2f Vec2f.cpp )
add_executable( Vec2d Vec2d.cpp )
add_executable( Vec2 Vec2.cpp )
