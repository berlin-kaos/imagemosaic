set(CMAKE_C_FLAGS "-Wall -g")

file(GLOB SRCS *.c *.h *.cpp)

find_package(ImageMagick COMPONENTS Magick++)

add_executable(imagemosaic ${SRCS})

include_directories(${ImageMagick_INCLUDE_DIRS})
target_link_libraries(imagemosaic ${ImageMagick_LIBRARIES})