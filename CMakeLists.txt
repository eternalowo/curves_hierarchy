cmake_minimum_required(VERSION 3.8)

project(technical_specification)

set(HDR 
    src/curve/curve_interface.h 
    src/circle/circle.h
    src/ellipse/ellipse.h
    src/helix/helix.h
    src/point/point.h
    src/curves_filler/curves_filler.h
)

set(SRC
    src/circle/circle.cpp
    src/ellipse/ellipse.cpp
    src/helix/helix.cpp
    src/curves_filler/curves_filler.cpp
    src/main.cpp
)

OPTION (USE_OpenMP "Use OpenMP" ON)
IF(USE_OpenMP)
  FIND_PACKAGE(OpenMP)
  IF(OPENMP_FOUND)
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
  ENDIF()
ENDIF()

add_executable(curves_hierarchy ${SRC})

target_include_directories(curves_hierarchy PRIVATE
    src/curve
    src/circle
    src/curves_filler
    src/ellipse
    src/helix
    src/point
)

target_sources(curves_hierarchy PRIVATE ${HDR})

target_compile_features(curves_hierarchy PRIVATE cxx_std_20)
