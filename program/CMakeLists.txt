cmake_minimum_required(VERSION 3.4)

project(Program)

#ustaw we w�asnej zmiennej SOURCE_FILES zbi�r plik�w �r�d�owych projektu
set(SOURCE_FILES
        src/main.cpp
        src/Interface.cpp)
#w��cz powy�szy zbi�r plik�w do zbudowania programu wykonywalnego Program
add_executable(Program ${SOURCE_FILES})
#Okre�lenie zale�no�ci pomi�dzy projektami Program i Biblioteka
target_link_libraries(Program Biblioteka)

#do��cz katalog include podprojektu Program do globalnej listy. Dzi�ki temu ka�dy inny podprojekt b�dzie ten katalog "widzia�"
target_include_directories(Program PUBLIC include)

enable_testing()