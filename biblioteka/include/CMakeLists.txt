cmake_minimum_required(VERSION 3.8)
project(projekt)

set(CMAKE_CXX_STANDARD 11)

add_executable(projekt main.cpp Address.cpp 
Address.h Bicycle.cpp Bicycle.h Car.cpp Car.h 
Client.cpp Client.h ClientRepository.cpp ClientRepository.h ClientTypes.cpp ClientTypes.h Mope.cpp Mope.h MotorVehicle.cpp 
MotorVehicle.h Rent.cpp Rent.h RentsManager.cpp RentsManager.h Vehicle.cpp Vehicle.h VehicleRepository.cpp VehicleRepository.h Generator.cpp Generator.h 
RentsRepository.cpp RentsRepository.h)