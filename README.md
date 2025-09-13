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

verbose

```bash
ctest --rerun-failed --output-on-failure
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
      Start  1: GraphCasesTest.SampleGraphsAreIsomorphic
 1/33 Test  #1: GraphCasesTest.SampleGraphsAreIsomorphic ..........................   Passed    0.01 sec
      Start  2: GraphCasesTest.AnotherPairIsomorphic
 2/33 Test  #2: GraphCasesTest.AnotherPairIsomorphic ..............................   Passed    0.00 sec
      Start  3: GraphIsomorphismTest.GraphIsomorphicToItselfDisconnected
 3/33 Test  #3: GraphIsomorphismTest.GraphIsomorphicToItselfDisconnected ..........   Passed    0.00 sec
      Start  4: GraphIsomorphismTest.GraphIsomorphicToItself
 4/33 Test  #4: GraphIsomorphismTest.GraphIsomorphicToItself ......................   Passed    0.00 sec
      Start  5: GraphIsomorphismTest.DifferentVertexCountNotIsomorphic
 5/33 Test  #5: GraphIsomorphismTest.DifferentVertexCountNotIsomorphic ............   Passed    0.00 sec
      Start  6: GraphIsomorphismTest.DifferentEdgeCountNotIsomorphic
 6/33 Test  #6: GraphIsomorphismTest.DifferentEdgeCountNotIsomorphic ..............   Passed    0.00 sec
      Start  7: GraphIsomorphismTest.DifferentDegreeSequenceNotIsomorphic
 7/33 Test  #7: GraphIsomorphismTest.DifferentDegreeSequenceNotIsomorphic .........   Passed    0.01 sec
      Start  8: GraphIsomorphismTest.NonIsomorphicSameDegreeSequence
 8/33 Test  #8: GraphIsomorphismTest.NonIsomorphicSameDegreeSequence ..............   Passed    0.01 sec
      Start  9: GraphIsomorphismTest.IsomorphicGraphsDifferentLabeling
 9/33 Test  #9: GraphIsomorphismTest.IsomorphicGraphsDifferentLabeling ............   Passed    0.00 sec
      Start 10: CGraphTest.ConstructorInitializesVertices
10/33 Test #10: CGraphTest.ConstructorInitializesVertices .........................   Passed    0.01 sec
      Start 11: CGraphTest.AddEdgeUndirectedAdjacency
11/33 Test #11: CGraphTest.AddEdgeUndirectedAdjacency .............................   Passed    0.00 sec
      Start 12: CGraphTest.AddEdgeDuplicateAllowsDuplicates
12/33 Test #12: CGraphTest.AddEdgeDuplicateAllowsDuplicates .......................   Passed    0.00 sec
      Start 13: CGraphTest.RemoveEdgeNoEffect
13/33 Test #13: CGraphTest.RemoveEdgeNoEffect .....................................   Passed    0.00 sec
      Start 14: CGraphTest.AdjacentAndDegreeWithNoEdges
14/33 Test #14: CGraphTest.AdjacentAndDegreeWithNoEdges ...........................   Passed    0.00 sec
      Start 15: CGraphTest.StaticCompareVerticesQuantity
15/33 Test #15: CGraphTest.StaticCompareVerticesQuantity ..........................   Passed    0.00 sec
      Start 16: CGraphTest.StaticEdgesCountAndCompare
16/33 Test #16: CGraphTest.StaticEdgesCountAndCompare .............................   Passed    0.00 sec
      Start 17: CGraphTest.StaticDegreeTableFunctions
17/33 Test #17: CGraphTest.StaticDegreeTableFunctions .............................   Passed    0.00 sec
      Start 18: ReadInputTest.FileSizeCountsLines
18/33 Test #18: ReadInputTest.FileSizeCountsLines .................................   Passed    0.00 sec
      Start 19: ReadInputTest.GetVertexQuantityParsesFirstLine
19/33 Test #19: ReadInputTest.GetVertexQuantityParsesFirstLine ....................   Passed    0.00 sec
      Start 20: ReadInputTest.ReadInputBuildsGraphCorrectly
20/33 Test #20: ReadInputTest.ReadInputBuildsGraphCorrectly .......................   Passed    0.00 sec
      Start 21: HelloWorldTest.BasicAssertions
21/33 Test #21: HelloWorldTest.BasicAssertions ....................................   Passed    0.00 sec
      Start 22: CVertexAdjacencyListTest.DefaultConstructorInitializesEmptyList
22/33 Test #22: CVertexAdjacencyListTest.DefaultConstructorInitializesEmptyList ...   Passed    0.00 sec
      Start 23: CVertexAdjacencyListTest.InitiallyEmpty
23/33 Test #23: CVertexAdjacencyListTest.InitiallyEmpty ...........................   Passed    0.00 sec
      Start 24: CVertexAdjacencyListTest.CanSetAndGetVertexValue
24/33 Test #24: CVertexAdjacencyListTest.CanSetAndGetVertexValue ..................   Passed    0.00 sec
      Start 25: CVertexAdjacencyListTest.AddIncreasesSize
25/33 Test #25: CVertexAdjacencyListTest.AddIncreasesSize .........................   Passed    0.00 sec
      Start 26: CVertexAdjacencyListTest.AddSingleElement
26/33 Test #26: CVertexAdjacencyListTest.AddSingleElement .........................   Passed    0.00 sec
      Start 27: CVertexAdjacencyListTest.IsAnElementWorksCorrectly
27/33 Test #27: CVertexAdjacencyListTest.IsAnElementWorksCorrectly ................   Passed    0.00 sec
      Start 28: CVertexAdjacencyListTest.AddMultipleElements
28/33 Test #28: CVertexAdjacencyListTest.AddMultipleElements ......................   Passed    0.00 sec
      Start 29: CVertexAdjacencyListTest.ElementAtIndexReturnsCorrectValue
29/33 Test #29: CVertexAdjacencyListTest.ElementAtIndexReturnsCorrectValue ........   Passed    0.00 sec
      Start 30: CVertexAdjacencyListTest.ElementAtIndexOutOfRange
30/33 Test #30: CVertexAdjacencyListTest.ElementAtIndexOutOfRange .................   Passed    0.00 sec
      Start 31: CVertexAdjacencyListTest.AddDuplicateValue
31/33 Test #31: CVertexAdjacencyListTest.AddDuplicateValue ........................   Passed    0.00 sec
      Start 32: CVertexAdjacencyListTest.SetAndGetVertexValue
32/33 Test #32: CVertexAdjacencyListTest.SetAndGetVertexValue .....................   Passed    0.00 sec
      Start 33: CVertexAdjacencyListTest2.ElementAtIndexOutOfRange2
33/33 Test #33: CVertexAdjacencyListTest2.ElementAtIndexOutOfRange2 ...............   Passed    0.00 sec

100% tests passed, 0 tests failed out of 33

Total Test time (real) =   0.15 sec
```
