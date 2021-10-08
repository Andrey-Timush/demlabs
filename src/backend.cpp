#include <QDebug>
#include "backend.h"
#include <QStandardPaths>

Backend::Backend(QObject *parent) : QObject(parent),
    m_comboList(m_list)
{
    m_comboList = m_list;
    socket = new QUdpSocket(this); 
}

const QStringList Backend::comboList()
{
    return m_comboList;
}

void Backend::setComboList(QStringList comboList)
{
    QStringList list;
    //list += "Moscow";
    //list += "Saint-Petersburg";
    //list += "Novosibirsk";
    m_comboList = comboList;
    emit comboListChanged();
}

int Backend::count()
{
    return m_count;
}

void Backend::setCount(int cnt)
{
    if (cnt != m_count)
    {
        m_count = cnt;
        emit countChanged();
    }
}

int Backend::currentIndex()
{
    return m_currentIndex;
}

void Backend::setcurrentIndex(int index)
{
    if (index != m_currentIndex)
    {
        m_currentIndex = index;
        emit currentIndexChanged();
    }
}
void Backend::addElement(const QString &element)
{
    m_comboList.append(element);
    emit comboListChanged();
    setCount(m_comboList.count());
    emit countChanged();
}

void Backend::removeElement(int index)
{
    if (index < m_comboList.count())
    {
        m_comboList.removeAt(index);
        emit comboListChanged();
        setCount(m_comboList.count());
        emit countChanged();
    }
}

void Backend::sendMessage(QString message) 
{
    qDebug() << message;
    //socket = new QUdpSocket(this);
    //socket->bind(QHostAddress::LocalHost, 7000);
}

