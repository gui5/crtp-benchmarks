cmake_minimum_required(VERSION 3.2)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/modules/vcpkg/scripts/buildsystems/vcpkg.cmake 
	CACHE STRING "Vcpkg toolchain file")

project(crtp_bench VERSION 0.0.1 LANGUAGES CXX)
enable_testing()

find_package(benchmark CONFIG REQUIRED)



add_executable(bench	"bench/bench.cpp"
						"include/crtp.hpp"
						"include/poly.hpp"
						"src/poly.cpp"
						"include/crtp_concept.hpp")

set_target_properties(bench PROPERTIES
  CXX_STANDARD 20
  CXX_STANDARD_REQUIRED ON
  CXX_EXTENSIONS ON
)

target_include_directories(bench PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(bench PRIVATE benchmark::benchmark
									benchmark::benchmark_main)

add_executable(testdriver	"test/bench_test.cpp"  
							"include/crtp.hpp"
							"include/poly.hpp" 
							"src/poly.cpp"
							"include/crtp_concept.hpp")

set_target_properties(testdriver PROPERTIES
  CXX_STANDARD 20
  CXX_STANDARD_REQUIRED ON
  CXX_EXTENSIONS ON
)

target_include_directories(testdriver PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

find_package(GTest CONFIG REQUIRED)
target_link_libraries(testdriver PRIVATE	GTest::gtest
											GTest::gtest_main)
											

add_test(NAME Implementation COMMAND testdriver)
