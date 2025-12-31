cmake_minimum_required(VERSION 3.10)
project(TrafficControlSystem)

# Utilisation de C++17 pour la compatibilité
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Lister tous les fichiers sources (.cpp) automatiquement
# Inclut main.cpp et tous les fichiers du dossier src
file(GLOB SOURCES
    "main.cpp"
    "src/*.cpp"
)

# 2. Sécurité : Exclure les fichiers qui créent des conflits (double main)
# On retire les fichiers qui causaient des erreurs de liaison
list(FILTER SOURCES EXCLUDE REGEX "visualisation_raylib.cpp")
list(FILTER SOURCES EXCLUDE REGEX "visualisation_raylib.cpp.old")

# 3. Indiquer où se trouvent les fichiers d'en-tête (.h)
# On inclut le dossier racine et le dossier include
include_directories(.)
include_directories(include)

# 4. Créer l'exécutable
add_executable(${PROJECT_NAME} ${SOURCES})

# 5. Liaison manuelle des bibliothèques (La méthode robuste pour Linux)
# On lie raylib et ses dépendances système obligatoires
target_link_libraries(${PROJECT_NAME}
    raylib
    GL
    m
    pthread
    dl
    rt
    X11
)