#include <jvanz/graph.hpp>

using namespace std;

namespace jvanz {
namespace graph {

static int floyd_warshall( )
{
	throw "Not implemented";
}

future<int> find_shortest_path_all_pairs()
{
	return async(floyd_warshall);
}

} // namespace graph
} // namespace jvanz
