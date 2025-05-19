set(target ${TREES_LIBRARY})

file(GLOB hdrs "*.h*" "${TREES_INCLUDE}/*.h*")
file(GLOB srcs "*.cpp")

add_library(${target} STATIC ${srcs} ${hdrs})
target_link_libraries(${target} ${LIBRARY_DEPS})
