#Minimalna wersja cmake konieczna do zbudowania tego projektu
cmake_minimum_required(VERSION 3.4)

#Parametry konfiguracyjne platformy programistycznej i flagi kompilatora
set(CMAKE_CXX_COMPILER g++)#g++ jako kompilator C++
set(CMAKE_C_COMPILER gcc)#gcc jako kompilator C
set(CMAKE_CXX_STANDARD 11)#Standard C++ 11, bez tego parametru g++ u�yje warto�ci domy�lnej. Dla g++ od wersji 6 jest to C++14
set(CMAKE_CXX_STANDARD_REQUIRED ON)#Okre�lony wy�ej standard C++ jest wymagany

#Profil debug i maksymalny poziom debug info g3 oraz format debug info na dwarf-4 (musi by� gdb w wersji 7). BUILD_TYPE mo�e by� ustawiony na:
#empty,
#Debug,
#Release,
#RelWithDebInfo
#MinSizeRel
#Ustawiono dodatkowo flagi debug generuj�ce informacj� dla debuggera
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS_DEBUG "-g3 -gdwarf-4")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -gdwarf-4")

#Ustaw nazw� projektu i j�zyk na C++
project(Warsztat_4)
enable_language(CXX)

#W specjalnym pliku compile_commands.json mo�na podejrze� wszystkie operacje kompilatora wraz z parametrami, 
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE TRUE)

#uwzgl�dnij podprojek znajduj�cy si� w podkatalogu program. Musi by� w nim pliki CMakeLists.txt
add_subdirectory(program)
add_subdirectory(biblioteka)

#W��czenie test�w powoduje pojawienie si� celu test w makefiles
enable_testing()