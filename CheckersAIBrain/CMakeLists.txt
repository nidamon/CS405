# CMakeList.txt : CMake project for CheckersAIBrain, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("CheckersAIBrain")

find_package(Torch REQUIRED)

# Add source to this project's executable.
add_executable (CheckersAIBrain "CheckersAIBrain.cpp" "CheckersAIBrain.h")
target_link_libraries(CheckersAIBrain "${TORCH_LIBRARIES}")

if (MSVC)
  file(GLOB TORCH_DLLS "${TORCH_INSTALL_PREFIX}/lib/*.dll")
  add_custom_command(TARGET CheckersAIBrain
                     POST_BUILD
                     COMMAND ${CMAKE_COMMAND} -E copy_if_different
                     ${TORCH_DLLS}
                     $<TARGET_FILE_DIR:CheckersAIBrain>)
endif (MSVC)

# TODO: Add tests and install targets if needed.
