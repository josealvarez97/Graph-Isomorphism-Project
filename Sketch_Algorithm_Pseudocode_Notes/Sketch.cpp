class Graph
{


private:
	List<Vertex*> VertexList;
public:
	int GetQuantityOfVertexs()
	{
		return VertexList.Size();
	}

	int GetVertexDegree(int vertex)
	{
		return vertex.AdjacencyList.Size();
	}

	List<int> GetNeighbors(int vertex);
	{
		return vertex.adjacencyList();

	}

};

struct Vertex
{

public:
	INT ID;
	//List<Vertex*> AdjacencyList;
	List<int> AdjacencyList; 


}