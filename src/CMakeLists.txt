set(CMAKE_C_FLAGS "-Wall -g")
set(Boost_USE_STATIC_LIBS ON)

file(GLOB SRCS *.c *.h *.cpp)

find_package(ImageMagick COMPONENTS Magick++ REQUIRED)
find_package(Boost 1.48 COMPONENTS system program_options REQUIRED)

link_directories(${Boost_LIBRARY_DIRS})

include_directories(${ImageMagick_INCLUDE_DIRS})
include_directories(${Boost_INCLUDE_DIRS})

add_executable(imagemosaic ${SRCS})

target_link_libraries(imagemosaic ${ImageMagick_LIBRARIES})
target_link_libraries(imagemosaic ${Boost_LIBRARIES})