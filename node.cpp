#include "node.h"

Node::Node(QString name)
{
	m_Name = name;
}

void Node::addEdge(Node* n)
{
	m_Edges.append(n);
}

QList<Node*> Node::Edges() const
{
	return m_Edges;
}

QString Node::Name() const
{
	return m_Name;
}
