cmake_minimum_required(VERSION 3.16.0)

project(FilterSpatialDomain)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(OpenCV REQUIRED COMPONENTS core highgui imgproc features2d calib3d) 
include_directories(${OpenCV_INCLUDE_DIRS})

message( [opencv] ${OpenCV_INCLUDE_DIRS} )
message( [opencv] ${${OpenCV_LIBS}} )
message( [opencv] ${${OpenCV_LIBRARIES}} )


add_executable(${PROJECT_NAME} 
    src/Main.cpp src/Convolution.cpp src/EdgeDetector.cpp src/Blur.cpp
)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBRARIES})