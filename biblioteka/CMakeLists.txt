cmake_minimum_required(VERSION 3.4)
project(Biblioteka)

set(SOURCE_FILES
        src/Client.cpp
        src/Address.cpp
        src/Rent.cpp
        src/Vehicle.cpp
        src/MotorVehicle.cpp
        src/Bicycle.cpp
        src/Car.cpp
        src/Mope.cpp
        src/RentsRepository.cpp
        src/VehicleRepository.cpp
        src/ClientTypes.cpp
        src/ClientRepository.cpp
        src/RentsManager.cpp
        )

#utw�rz bibliotek� typu STATIC, SHARED albo MODULE ze wskazanych �r�de�
add_library(Biblioteka ${SOURCE_FILES})

target_include_directories(Biblioteka PUBLIC include)

enable_testing()

#Sekcja test�w
find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_CLIENT_FILES
        test/master.cpp
        test/ClientTest.cpp)

add_executable (TestClient ${SOURCE_TEST_CLIENT_FILES})

target_link_libraries (TestClient
        Biblioteka
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

set(SOURCE_TEST_RENT_FILES
        test/master.cpp
        test/RentTest.cpp)

#add_executable (TestRent ${SOURCE_TEST_RENT_FILES})

#target_link_libraries (TestRent
        #Biblioteka
        #${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        #)

set(SOURCE_TEST_ADDRESS_FILES
        test/master.cpp
        test/AddressTest.cpp)

add_executable (TestAddress ${SOURCE_TEST_ADDRESS_FILES})

target_link_libraries (TestAddress
        Biblioteka
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

set(SOURCE_TEST_VEHICLE_FILES
        test/master.cpp
        test/VehicleTest.cpp)

add_executable (TestVehicle ${SOURCE_TEST_VEHICLE_FILES})

target_link_libraries (TestVehicle
        Biblioteka
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

enable_testing()

add_test(TestBiblioteki1 TestClient
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )

add_test(NAME TestBiblioteki2 COMMAND TestAddress
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )

add_test(NAME TestBiblioteki3 COMMAND TestRent
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )

add_test(NAME TestBiblioteki4 COMMAND TestVehicle
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})