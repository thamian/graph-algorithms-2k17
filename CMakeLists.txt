cmake_minimum_required(VERSION 2.6)
project(graph-algorithms-2k17)

set(CMAKE_CXX_STANDARD 11)
set(DCMAKE_CXX_FLAGS=-pg -DCMAKE_EXE_LINKER_FLAGS=-pg -DCMAKE_SHARED_LINKER_FLAGS=-pg)
include_directories(Graph LinkedList Heap Algorithm)
set(SOURCE_FILES
        main.cpp
        Controller/Controller.cpp
        Interface/Menu.cpp
        Interface/File.cpp
        Graph/ListGraph.cpp
        Graph/MatrixGraph.cpp
        Graph/Graph.cpp
        Interface/Console.cpp
        Interface/Message.cpp
        LinkedList/LinkedList.cpp
        LinkedList/Node.cpp
        TreeAlgorithm/Prim/Prim.cpp
        TreeAlgorithm/Prim/Prim.h
        TreeAlgorithm/Kruskal/Kruskal.cpp
        TreeAlgorithm/Kruskal/Kruskal.h
        PathAlgorithm/BellmanFord/BellmanFord.cpp
        PathAlgorithm/BellmanFord/BellmanFord.h
        PathAlgorithm/Dijkstra/Dijkstra.cpp
        PathAlgorithm/Dijkstra/Dijkstra.h
        Algorithm/Algorithm.cpp
        Algorithm/Algorithm.h
        Heap/Heap.cpp
        Heap/Heap.h
        PathAlgorithm/PathAlgorithm.cpp
        PathAlgorithm/PathAlgorithm.h
        TreeAlgorithm/TreeAlgorithm.cpp
        TreeAlgorithm/TreeAlgorithm.h
        Heap/EdgeHeap.cpp
        Heap/EdgeHeap.h
        Graph/Edge.cpp
        Graph/Edge.h
        ArrayList/ArrayList.cpp
        ArrayList/ArrayList.h
        TreeAlgorithm/Kruskal/Subset.cpp
        TreeAlgorithm/Kruskal/Subset.h
        Generator.cpp
        Generator.h)
add_executable(graph-algorithms-2k17 ${SOURCE_FILES})
