cmake_minimum_required(VERSION 3.26)
project(progcpp_TP01_ELGANA_mono)

set(CMAKE_CXX_STANDARD 17)
file(GLOB EXERCISES "exercice-*.cpp")

foreach(src ${EXERCISES})
    get_filename_component(exe ${src} NAME_WE)
    add_executable(${exe} ${src})
endforeach()

add_custom_target(build_all
        DEPENDS ${EXERCISES}
        COMMENT "Building all TP01 exercises (1a to 1d)..."
)