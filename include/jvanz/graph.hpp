#ifndef __JVANZ_GRAPH_HPP__
#define __JVANZ_GRAPH_HPP__

#include <vector>
#include <tuple>
#include <future>

using namespace std;

namespace jvanz {
namespace graph {

typedef tuple<unsigned int,unsigned int, int> edge_tuple;

future<int> find_shortest_path_all_pairs();

} // namespace graph
} // namespace jvanz

#endif
