# Graph-Isomorphism-Project

# Legacy docs (Spanish)

To understand what was originally going on here, please check out the detailed [legacy documentation](https://github.com/josealvarez97/Graph-Isomorphism-Project/tree/master/Documentation) - which is in Spanish, though. But it's very good legacy documentation (at least check out the diagrams and pictures of the [Technical Manual](../master/Documentation/Entrega/Documentacion/Manuales/MANUAL_TECNICO_PROYECTO.pdf) :wink:).

# 2025 Update - English

I removed all the Visual Studio project files from the `GraphIsomorphism_Version_1.0` folder. (Actually, they are still at `Legacy_Docs/Entrega/Documentacion/Codigo Fuente`, but that's irrelevant.)

Instead, I now added a `CMakeLists.txt` to the root of the repo. If you follow the instructions below, you'll be able to build the program and run it seamlessly.

Just open your terminal, navigate to the root of the repo, and follow the instructions below.

## Build with CMake

Make sure CMake is installed. Also make sure you have a C++ compiler available (e.g. GCC, Clang, or MSVC on Windows).

### Generate a build directory

```bash
mkdir build
cd build
```

### Run CMake configuration

```bash
cmake ..
```

### Build the project

```bash
cmake --build .
```

### Run the program

```bash
./GraphIsomorphisim_Version_1.0
```

You should experience something like this:

```bash
***Insert the first graph txt file data adress (must be complete absolute path, not relative path)
/Users/anyuser/Documents/GitHub/Graph-Isomorphism-Project/GraphIsomorphisim_Version_1.0/Cases/Grafo1.txt
Reading vertex quantity from file: /Users/anyuser/Documents/GitHub/Graph-Isomorphism-Project/GraphIsomorphisim_Version_1.0/Cases/Grafo1.txt
Vertex quantity: 6

***Insert the second graph txt file data adress (must be complete absolute path, not relative path)
/Users/anyuser/Documents/GitHub/Graph-Isomorphism-Project/GraphIsomorphisim_Version_1.0/Cases/Grafo2.txt
Reading vertex quantity from file: /Users/anyuser/Documents/GitHub/Graph-Isomorphism-Project/GraphIsomorphisim_Version_1.0/Cases/Grafo2.txt
Vertex quantity: 6

|--------------------------------
| GRAPH A:
| - Vertices Quantity: 6
| - Edges Quantity: 12
| - Vertex per Degree:
|  | Degree | # of Vertex
|  |   0    |     0
|  |   1    |     0
|  |   2    |     0
|  |   3    |     0
|  |   4    |     6
|--------------------------------
| GRAPH B:
| - Vertices Quantity: 6
| - Edges Quantity: 12
| - Vertex per Degree:
|  | Degree | # of Vertex
|  |   0    |     0
|  |   1    |     0
|  |   2    |     0
|  |   3    |     0
|  |   4    |     6
|--------------------------------
ISOMORPHISM FUNCTION
G1 -> G2
0 -> 0
1 -> 1
2 -> 2
3 -> 5
4 -> 3
5 -> 4


  DO YOU WANT TO CONTINUE INSERTING OTHER GRAPHS? YES: Any key  NO: press 1
```
