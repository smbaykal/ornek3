#ifndef GRAPH_H
#define GRAPH_H

#include <QList>
#include <QHash>

#include "node.h"

class Graph
{
public:
	explicit Graph();

	explicit Graph(QList<Node*> nodes);

	bool addNode(Node* node);

	bool addEdge(Node* from, Node* to);

	bool isCyclicDependencyExists();

	QList<Node *> topologicalSortKahn();

	QList<Node*> topologicalSortDFS();

	QList<Node *> nodes() const;

private:
	QList<Node*> m_nodes;
	QHash<Node*, QList<Node*>> m_edges;
};

#endif // GRAPH_H
