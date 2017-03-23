#include <fstream>
#include <limits>

#include <gtest/gtest.h>

using namespace std;

typedef vector<vector<int>> Graph;

static Graph ReadAssignment4Data(const string file_path)
{
	ifstream file (file_path, ifstream::in);
	if (file.good()){
		int vertices; int edges;
		file >> vertices >> edges;
		Graph g(vertices, vector<int>(vertices, numeric_limits<int>::max()));
		for (auto i = 0; i < edges; ++i){
			unsigned int source; unsigned int dest; int cost;
			file >> source >> dest >> cost;
			g[source-1][dest-1] = cost;
			if (file.bad())
				throw "Error while reading input file";
		}
		return g;
	}
	throw "Can not read input file";
}

static void floyd_warshall(Graph& graph)
{
	auto vertices = graph.size();
	// initialize default values of the diagonal
	for (auto i = 0; i < vertices; ++i)
		graph[i][i] = 0;
	for (auto k = 0; k < vertices; ++k){
		for (auto i = 0; i < vertices; ++i){
			for (auto j = 0; j < vertices; ++j){
				if (graph[i][j] > graph[i][k] + graph[k][j])
					graph[i][j] = graph[i][k] + graph[k][j];
			}
		}
	}
}

TEST(Assignment4, Algorith2MOOCCoursera) {
	auto graph = ReadAssignment4Data("data/g1.txt");
	ASSERT_EQ(graph.size(),1000);
	ASSERT_EQ(graph[0].size(),1000);
	ASSERT_EQ(graph[0][13],6);
	ASSERT_EQ(graph[999][987],3);
	floyd_warshall(graph);
	graph = ReadAssignment4Data("data/g2.txt");
	ASSERT_EQ(graph.size(),1000);
	ASSERT_EQ(graph[0].size(),1000);
	ASSERT_EQ(graph[0][1],2);
	ASSERT_EQ(graph[999][987],3);
	graph = ReadAssignment4Data("data/g3.txt");
	ASSERT_EQ(graph.size(),1000);
	ASSERT_EQ(graph[0].size(),1000);
	ASSERT_EQ(graph[0][7],36);
	ASSERT_EQ(graph[999][978],1);
}

