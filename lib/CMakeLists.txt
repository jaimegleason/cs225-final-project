# Path definitions.
set(lib_dir ${CMAKE_CURRENT_SOURCE_DIR})


# Add cs225 library.
set(cs225_dir ${lib_dir}/cs225)
file(GLOB_RECURSE cs225_sources CONFIGURE_DEPENDS ${cs225_dir}/*.cpp)
add_library(cs225 ${cs225_sources})
target_include_directories(cs225 PRIVATE ${lib_dir})


# Add overall libs library.
add_library(libs INTERFACE)
target_include_directories(libs INTERFACE ${lib_dir})
target_link_libraries(libs INTERFACE cs225)