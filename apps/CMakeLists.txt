add_executable(binaryTree binary_tree.cpp)
target_link_libraries(binaryTree PRIVATE project_warnings project_options catch_main ${PROJECT_LIB_NAME})
