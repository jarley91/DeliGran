cmake_minimum_required(VERSION 3.5)

project(TestDGR VERSION 1.0.0 LANGUAGES C)

add_executable(${PROJECT_NAME}
  src/TestDGR.c
  src/entities/User.c
  src/entities/Enterprise.c
  src/controllers/DefaultController.c
)

target_include_directories(${PROJECT_NAME}
  PUBLIC /usr/include
  PRIVATE ../DeliGran/include/DeliGranUtils/lib/entities
  PRIVATE ../DeliGran/include/DeliGranDB/lib/entities
  PRIVATE ../DeliGran/include/DeliGranRest/lib
  PRIVATE ../DeliGran/include/DeliGranRest/lib/entities
)

target_link_directories(${PROJECT_NAME}
  PUBLIC /usr/lib
  PRIVATE ../DeliGran/libs
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE deligranutils deligrandb deligranrest
)
