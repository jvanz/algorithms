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
			if (file.bad())
				throw "Error while reading input file";
		}
		return g;
	}
	throw "Can not read input file";
}

static bool validate_values(const Graph& g)
{
	for (unsigned int i = 0; i < g.size(); ++i){
		for (unsigned int ii = 0; ii < g[i].size(); ++ii){
			if (g[i][ii] != numeric_limits<int>::max())
				return false;
		}
	}
	return true;
}

TEST(Assignment4, Algorith2MOOCCoursera) {
	auto graph = ReadAssignment4Data("data/g1.txt");
	ASSERT_EQ(graph.size(),1000);
	ASSERT_EQ(graph[0].size(),1000);
	ASSERT_TRUE(validate_values(graph));
	graph = ReadAssignment4Data("data/g2.txt");
	ASSERT_EQ(graph.size(),1000);
	ASSERT_EQ(graph[0].size(),1000);
	ASSERT_TRUE(validate_values(graph));
	graph = ReadAssignment4Data("data/g3.txt");
	ASSERT_EQ(graph.size(),1000);
	ASSERT_EQ(graph[0].size(),1000);
	ASSERT_TRUE(validate_values(graph));
}

