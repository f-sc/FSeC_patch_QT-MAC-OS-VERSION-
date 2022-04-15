#ifndef HEXTABLEMODEL_H
#define HEXTABLEMODEL_H

#include <QAbstractTableModel>
#include <QItemSelection>
#include <QMap>
#include <QColor>

#include <QDebug>

struct HexItem {
    QString m_Value;
    QString m_InitialValue;
    bool m_isChanged;
};

class HexTableModel : public QAbstractTableModel
{
    Q_OBJECT
    int m_LinesCount;
    QMap<QModelIndex, HexItem> m_DataStorage;
public:
    explicit HexTableModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    bool setData(const QModelIndex& index, const QVariant &value, int role = Qt::EditRole) override;
    void Clear();
    void Reflesh();
    void setApproxLinesCount(const int count);
signals:
    void reactHistoryUpdate(const QModelIndex& index);
    //void selectionChanged(const QItemSelection &selected, const QItemSelection &deselected);

};

#endif // HEXTABLEMODEL_H
