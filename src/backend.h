#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QUdpSocket>
#include <QByteArray>
#include <QDataStream>

class Backend : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QStringList comboList READ comboList WRITE setComboList NOTIFY comboListChanged)
    Q_PROPERTY(int count READ count WRITE setCount NOTIFY countChanged)
    Q_PROPERTY(int currentIndex READ currentIndex WRITE setcurrentIndex NOTIFY currentIndexChanged)    
    
public:
    explicit Backend(QObject *parent = nullptr);
    const QStringList comboList();

    void setComboList(QStringList comboList);

    int count();
    void setCount(int cnt);

    int currentIndex();
    void setcurrentIndex(int index);

    Q_INVOKABLE void addElement(const QString &element);
    Q_INVOKABLE void removeElement(int index);

public slots:
    void sendMessage(QString message);

Q_SIGNALS:
    void comboListChanged();
    void countChanged();
    void currentIndexChanged();


private:
    QStringList m_comboList;
    int         m_count;
    int         m_currentIndex;
    QUdpSocket *socket;
};

#endif // BACKEND_H
