add_library(intel_src
  intelmkl.hpp
  intelmkl.cpp)

target_compile_definitions(intel_src PUBLIC ${BLA_DEFINITIONS})

target_link_libraries(intel_src PRIVATE ${BLAS_LIBRARIES})

target_include_directories(intel_src
  INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
  PRIVATE ${BLA_INCLUDE_DIR})

add_library(intel_src::intel_src ALIAS intel_src)

install (TARGETS intel_src DESTINATION bin)
install (FILES intelmkl.hpp DESTINATION include)
