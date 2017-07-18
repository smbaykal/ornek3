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

	QHash<int, QList<Node*>> calculateDepths();

	QList<Node *> topologicalSortKahn();

	QList<Node*> topologicalSortDFS();

	QList<Node *> nodes() const;

	QHash<Node *, QList<Node *> > edges() const;

private:
	void calculateDepthsUtil(Node* node, QHash<Node*, bool> *visited, int currentDepth, QHash<int, QList<Node*>> *depths);

	QList<Node*> m_nodes;
	QHash<Node*, QList<Node*>> m_edges;
};

#endif // GRAPH_H
