# Graph Isomorphism Project

# 2016 Legacy Docs (Spanish)

To understand what was originally going on here, please check out the detailed [legacy documentation](https://github.com/josealvarez97/Graph-Isomorphism-Project/tree/master/Documentation) - which is in Spanish, though. But it's very good legacy documentation (at least check out the diagrams and pictures of the [Technical Manual](../master/Documentation/Entrega/Documentacion/Manuales/MANUAL_TECNICO_PROYECTO.pdf) :wink:).

# 2025 Update - English

I removed all the Visual Studio project files from the `GraphIsomorphism_Version_1.0` folder. (Actually, they are still at `Legacy_Docs/Entrega/Documentacion/Codigo_Fuente/`, but that's irrelevant.)

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
./graph_iso
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

### Run the test suite

```bash
ctest --output-on-failure
```

or directly:

```bash
./graph_iso_tests
```

You probably want to convince the editor that the gtest package is there. At the root of the repo, run the following command (and don't forget to reload the window afterwards if you're using VS Code):

> **Note:** We’re creating a symlink at the repo root so editors like VS Code can find `compile_commands.json` for IntelliSense.  
> The real file lives in `build/` and is ignored by Git, but the symlink at the root points to it.  
> This way you get autocompletion without committing a large auto-generated file with details specific to your system.

```bash
cmake -S . -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
ln -s build/compile_commands.json .
```

If you run the tests, you should see something like this:

```bash
Test project /Users/josealvarez/Documents/GitHub/Graph-Isomorphism-Project/build
      Start  1: HelloWorldTest.BasicAssertions
 1/13 Test  #1: HelloWorldTest.BasicAssertions ....................................   Passed    0.00 sec
      Start  2: CVertexAdjacencyListTest.DefaultConstructorInitializesEmptyList
 2/13 Test  #2: CVertexAdjacencyListTest.DefaultConstructorInitializesEmptyList ...   Passed    0.00 sec
      Start  3: CVertexAdjacencyListTest.InitiallyEmpty
 3/13 Test  #3: CVertexAdjacencyListTest.InitiallyEmpty ...........................   Passed    0.00 sec
      Start  4: CVertexAdjacencyListTest.CanSetAndGetVertexValue
 4/13 Test  #4: CVertexAdjacencyListTest.CanSetAndGetVertexValue ..................   Passed    0.00 sec
      Start  5: CVertexAdjacencyListTest.AddIncreasesSize
 5/13 Test  #5: CVertexAdjacencyListTest.AddIncreasesSize .........................   Passed    0.00 sec
      Start  6: CVertexAdjacencyListTest.AddSingleElement
 6/13 Test  #6: CVertexAdjacencyListTest.AddSingleElement .........................   Passed    0.00 sec
      Start  7: CVertexAdjacencyListTest.IsAnElementWorksCorrectly
 7/13 Test  #7: CVertexAdjacencyListTest.IsAnElementWorksCorrectly ................   Passed    0.00 sec
      Start  8: CVertexAdjacencyListTest.AddMultipleElements
 8/13 Test  #8: CVertexAdjacencyListTest.AddMultipleElements ......................   Passed    0.00 sec
      Start  9: CVertexAdjacencyListTest.ElementAtIndexReturnsCorrectValue
 9/13 Test  #9: CVertexAdjacencyListTest.ElementAtIndexReturnsCorrectValue ........   Passed    0.00 sec
      Start 10: CVertexAdjacencyListTest.ElementAtIndexOutOfRange
10/13 Test #10: CVertexAdjacencyListTest.ElementAtIndexOutOfRange .................   Passed    0.00 sec
      Start 11: CVertexAdjacencyListTest.AddDuplicateValue
11/13 Test #11: CVertexAdjacencyListTest.AddDuplicateValue ........................   Passed    0.00 sec
      Start 12: CVertexAdjacencyListTest.SetAndGetVertexValue
12/13 Test #12: CVertexAdjacencyListTest.SetAndGetVertexValue .....................   Passed    0.00 sec
      Start 13: CVertexAdjacencyListTest2.ElementAtIndexOutOfRange2
13/13 Test #13: CVertexAdjacencyListTest2.ElementAtIndexOutOfRange2 ...............   Passed    0.00 sec

100% tests passed, 0 tests failed out of 13

Total Test time (real) =   0.05 sec
```
