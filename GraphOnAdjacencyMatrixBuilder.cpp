#include <QDebug>

#include "GraphOnAdjacencyMatrixBuilder.h"
#include "GraphOnAdjacencyMatrix.h"

GraphOnAdjacencyMatrixBuilder::GraphOnAdjacencyMatrixBuilder() {
    this->vertexList = new VertexList();
    vertexList->append(QPair<int, int>(0, 0));
    this->edgeList = new EdgeList();
}

GraphOnAdjacencyMatrixBuilder::~GraphOnAdjacencyMatrixBuilder() {
    delete this->vertexList;
    delete this->edgeList;
}

IGraphBuilder* GraphOnAdjacencyMatrixBuilder::addVertex(
        int coordinateX,
        int coordinateY
) {
    this->vertexList->append(QPair<int, int>(coordinateX, coordinateY));
    return this;
}

IGraphBuilder* GraphOnAdjacencyMatrixBuilder::addEdge(
        int firstVertex,
        int secondVertex
) throw (VertexNotFoundException) {
    if (firstVertex >= this->vertexList->length()) {
        throw VertexNotFoundException(firstVertex);
    }
    if (secondVertex>= this->vertexList->length()) {
        throw VertexNotFoundException(secondVertex);
    }
    this->edgeList->append(QPair<int, int>(firstVertex, secondVertex));
    return this;
}

::std::shared_ptr<IGraphComplete> GraphOnAdjacencyMatrixBuilder::build() throw (
        CanNotBuildAssociatedGraph, VertexNotFoundException

) {
    ::std::vector<::std::vector<short>> adjacencyMatrix(this->vertexList->length());

    for (int rowNumber = 1;
         rowNumber < this->vertexList->length();
         rowNumber++
    ) {
        adjacencyMatrix[rowNumber] = ::std::vector<short>(this->vertexList->length());
        for (int columnNumber = 1;
             columnNumber < this->vertexList->length();
             columnNumber++
        ) {
            adjacencyMatrix[rowNumber][columnNumber] = 0;
        }
    }
    for (int index = 0; index < this->edgeList->length(); index++) {
        int firstVertex = this->edgeList->at(index).first;
        int secondVertex = this->edgeList->at(index).second;
        adjacencyMatrix[firstVertex][secondVertex] = 1;
        adjacencyMatrix[secondVertex][firstVertex] = 1;
    }

    qDebug() << "print adjacencyMatrix";
    for (int i = 1; i < this->vertexList->length(); i++) {
        for (int j = 1; j < this->vertexList->length(); j++) {
            qDebug() << i << " " << j << " " << adjacencyMatrix[i][j];
        }
    }
    return ::std::make_shared<GraphOnAdjacencyMatrix>(
                VertexList(*this->vertexList),
                adjacencyMatrix
    );
}
