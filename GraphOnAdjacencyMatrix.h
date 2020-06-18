#ifndef GRAPHCOMPLETEIMPLEMENTATION_H
#define GRAPHCOMPLETEIMPLEMENTATION_H

#include "graph_interfaces/IGraphComplete.h"


class GraphOnAdjacencyMatrix: public IGraphComplete
{
private:
    VertexList vertexList;
    ::std::vector<::std::vector<short>> edgeMatrix;
public:
    GraphOnAdjacencyMatrix(
            VertexList vertexList,
            ::std::vector<::std::vector<short>> edgeMatrix
    );
    ~GraphOnAdjacencyMatrix();
private:
    ::std::vector<::std::vector<short>> createCopyOfEdgeMatrix();
    bool graphIsFullConnected(::std::vector<::std::vector<short>> edgeMatrix);

public:
    EdgeList provideEdges() override;

public:
    VertexList provideVertex() override;

public:
    void removeEdge(int firstVertex, int secondVertex) throw(
            CanNotRemoveEdgeException, VertexNotFoundException
    ) override;
};

#endif // GRAPHCOMPLETEIMPLEMENTATION_H
