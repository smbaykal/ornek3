#ifndef NODE_H
#define NODE_H

#include <QString>
#include <QList>

class Node
{
public:
	Node(QString name);

	QString name() const;

private:
	QString m_name;
};

#endif // NODE_H
