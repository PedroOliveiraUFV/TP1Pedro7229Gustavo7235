cmake_minimum_required(VERSION 3.10)
project(programa)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(Headers)

set(SOURCES
    main.c
    Source/CENTRODEPESQUISA.c
    Source/DADOPOKEMON.c
    Source/DADOTREINADOR.c
    Source/POKELISTA.c
)
add_executable(programa ${SOURCES})
target_link_libraries(programa m)
