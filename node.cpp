#include "node.h"

Node::Node(QString name)
{
	m_name = name;
}

QString Node::name() const
{
	return m_name;
}
