file(GLOB_RECURSE CORE_SRC "*.cpp" "*.hpp" "*.h")

set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.65.0 COMPONENTS *boost libraries here*) 

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
	add_executable(core ${CORE_SRC})
    target_link_libraries(progname ${Boost_LIBRARIES})
endif()
