#include "collection.h"

Collection::Collection(QString name) :
    m_name(name),
    m_items(QList<CollectionItem>())
{

}

QString Collection::name() const
{
    return m_name;
}

void Collection::setName(const QString &name)
{
    m_name = name;
}

QList<CollectionItem> Collection::items() const
{
    return m_items;
}

void Collection::setItems(const QList<CollectionItem> &items)
{
    m_items = items;
}