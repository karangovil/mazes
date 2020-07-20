macro (add_sources)
  file (RELATIVE_PATH _relPath "${CMAKE_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}")
  foreach (_src ${ARGN})
    if (_relPath)
      list (APPEND SOURCES "${CMAKE_SOURCE_DIR}/${_relPath}/${_src}")
    else()
      list (APPEND SOURCES "${CMAKE_SOURCE_DIR}/${_src}")
    endif()
  endforeach()
  if (_relPath)
    # propagate SOURCES to parent directory
    set (SOURCES ${SOURCES} PARENT_SCOPE)
  endif()
endmacro()

add_sources(cell.cpp
            grid.cpp)

set(CMAKE_SHARED_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
add_library(${PROJECT_LIB_NAME} SHARED ${SOURCES})

target_link_libraries(${PROJECT_LIB_NAME}
  PRIVATE project_options project_warnings)

target_include_directories(${PROJECT_LIB_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)
