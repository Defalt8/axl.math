cmake_minimum_required( VERSION 3.17 )

link_libraries( axl.math )

add_executable( lib lib.cpp )
add_executable( double double.cpp )
add_executable( float float.cpp )
