add_executable(game
    src/main.cpp
    src/Scenes/Adicional.cpp
    src/Scenes/EsDecrementable.cpp
    src/Scenes/Gameplay.cpp
    src/Scenes/Tittle.cpp
    src/Containers/AStar.cpp
    src/Containers/ColaCasillas.cpp
    src/Containers/ColaCasillasCustom.cpp
    src/Containers/ColaNodes.cpp
    src/Containers/DebugColaCasillas.cpp
)

target_include_directories(game PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(game PRIVATE engine)

set_target_properties(game PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
