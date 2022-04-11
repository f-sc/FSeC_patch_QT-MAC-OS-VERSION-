#include "HexTableModel.h"

HexTableModel::HexTableModel(QObject *parent)
    : QAbstractTableModel{parent}
{

}

int HexTableModel::rowCount(const QModelIndex &parent) const
{
    return m_LinesCount;
}

int HexTableModel::columnCount(const QModelIndex &parent) const
{
    return 16;
}

QVariant HexTableModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid()) { 
        if(role == Qt::DisplayRole || role == Qt::EditRole) {
            return m_DataStorage[index].m_Value;
        } else if(role == Qt::AccessibleTextRole) {
            return m_DataStorage[index].m_isChanged;
        } else if(role == Qt::ToolTipRole) {
            return m_DataStorage[index].m_InitialValue;
        }
    }
    return QVariant();
}

QVariant HexTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    QString tempValue = "";
    tempValue.setNum(section, 16);
    if (role == Qt::DisplayRole) {
            return "0x" + tempValue;
        }
    /*if(orientation == Qt::Vertical) {

    } else {

    }*/

    return QVariant();
}

Qt::ItemFlags HexTableModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags currentFlags = QAbstractTableModel::flags(index);
    currentFlags |= Qt::ItemIsEditable;
    return currentFlags;

}

bool HexTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!index.isValid()) {
        return false;
    }

    if(m_DataStorage[index].m_Value != value.toString()) {
        m_DataStorage[index].m_InitialValue = m_DataStorage[index].m_Value;
        m_DataStorage[index].m_Value = value.toString();
        if(role != Qt::DisplayRole) {
            m_DataStorage[index].m_isChanged = true;
            emit reactHistoryUpdate(index);
        }
    }
    return true;
}

void HexTableModel::Clear()
{
    resetInternalData();
}

void HexTableModel::Reflesh()
{
    emit dataChanged(index(0, 0),
                     index(rowCount(), columnCount()));
    emit layoutChanged();
}

void HexTableModel::setApproxLinesCount(const int count)
{
    m_LinesCount = count;
}
