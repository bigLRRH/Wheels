// MapReduce: Simplified Data Processing on Large Clusters
#include <list>
#include <vector>
template <typename _k, typename _v>
void emit(_k k, _v v) {}

template <typename _v>
void emit(_v v) {}

template <typename _k1, typename _v1, typename _k2, typename _v2>
void map(_k1 k1, _v1 v1)
{
    std::vector<_k2> k2s = v1.split();
    for (auto k2 : k2s)
        emit(k2, _v2.one());
}

template <typename _k, typename _v>
void reduce(_k k, std::list<_v> list_v)
{
    emit(list_v);
}