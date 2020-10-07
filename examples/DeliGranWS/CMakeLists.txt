cmake_minimum_required(VERSION 3.5)

project(DeliGranWS VERSION 1.0.0 LANGUAGES C)

add_executable(${PROJECT_NAME}
  src/DeliGranWS.c
  src/entities/Empresa.c
  src/controllers/EmpresasController.c
)

target_include_directories(${PROJECT_NAME}
  PUBLIC /usr/local/include
)

target_link_directories(${PROJECT_NAME}
  PUBLIC /usr/local/lib
  PRIVATE path/to/DeliGranRest
  PRIVATE path/to/${CMAKE_BUILD_TYPE}/DeliGranUtils
)

target_link_libraries(${PROJECT_NAME}
  PUBLIC microhttpd libfyaml
  PRIVATE deligranrest deligranutils
)
