cmake_minimum_required(VERSION 3.12)
project(H5CompositesExamples VERSION 0.1.0)

add_subdirectory(H5Composites)
add_library(H5CompositesExamples)
target_sources(H5CompositesExamples
    PRIVATE
    src/ParticleData.cxx
)
target_include_directories(H5CompositesExamples
    PUBLIC
    include
)
target_link_libraries(H5CompositesExamples
    PUBLIC
    H5Composites
)

add_executable(particles util/particles.cxx)
target_link_libraries(particles PRIVATE H5CompositesExamples)