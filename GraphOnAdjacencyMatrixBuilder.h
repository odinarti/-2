#ifndef GRAPHBUILDERIMPLEMENTATION_H
#define GRAPHBUILDERIMPLEMENTATION_H

#include "graph_interfaces/IGraphBuilder.h"
#include "graph_interfaces/IGraphEdgesProvider.h"
#include "graph_interfaces/IGraphVerticesProvider.h"


class GraphOnAdjacencyMatrixBuilder: public IGraphBuilder
{
private:
    VertexList* vertexList;
    EdgeList*   edgeList;
public:
    GraphOnAdjacencyMatrixBuilder();
    ~GraphOnAdjacencyMatrixBuilder();

public:
    IGraphBuilder* addVertex(int coordinateX, int coordinateY) override;
    IGraphBuilder* addEdge(int firstVertex, int secondVertex) throw(
            VertexNotFoundException
    ) override;
    ::std::shared_ptr<IGraphComplete> build() throw (
            CanNotBuildAssociatedGraph, VertexNotFoundException
    ) override;
};

#endif // GRAPHBUILDERIMPLEMENTATION_H
