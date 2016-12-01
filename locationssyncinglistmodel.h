#ifndef LOCATIONSSYNCINGLISTMODEL_H
#define LOCATIONSSYNCINGLISTMODEL_H

#include <QObject>
#include <QAbstractListModel>

class LocationsSyncingListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum ScrollViewRoleNames {
        imageUrl = Qt::UserRole + 1,
        name,
        sizeOnDisk,
        scopeID,
    };

    LocationsSyncingListModel();
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QHash<int, QByteArray> roleNames() const;

public slots:
    void OnSyncActionClicked(QString scopeID);
    void OnChooseFoldersClicked(QString scopeID);

private:
    struct SiteInfo {
        std::wstring name;
        std::wstring sizeOnDisk;
        std::wstring imageUrl;
        std::wstring scopeID;
    };

    std::vector<std::wstring> m_siteNames;
    std::vector<SiteInfo> m_siteInfoVector;
};

#endif // LOCATIONSSYNCINGLISTMODEL_H
