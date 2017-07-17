#ifndef NODE_H
#define NODE_H

#include <QString>
#include <QList>

class Node
{
public:
	Node(QString name);

	void addEdge(Node* n);

	QList<Node*> Edges() const;

	QString Name() const;

private:
	QList<Node*> m_Edges;
	QString m_Name;
};

#endif // NODE_H
