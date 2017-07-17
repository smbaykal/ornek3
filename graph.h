#ifndef GRAPH_H
#define GRAPH_H

#include <QList>

#include "node.h"

class Graph
{
public:
	explicit Graph();
	QString dependencyResolve(Node* node);

	QList<Node *> Resolved() const;

private:
	void dependencyResolveUtil(Node* node);

	QList<Node*> m_Resolved;
	QList<Node*> m_Unresolved;
	QString m_TraversedNodes;
	QString m_LastError;
};

#endif // GRAPH_H
