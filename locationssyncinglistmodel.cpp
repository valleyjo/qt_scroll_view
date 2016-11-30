#include "locationssyncinglistmodel.h"

using namespace std;

LocationsSyncingListModel::LocationsSyncingListModel()
{
    SiteInfo info1;
    info1.name = wstring(L"OneDrive - Contoso");
    info1.imageUrl = wstring(L"http://cdn.marketplaceimages.windowsphone.com/v8/images/bf05b44c-1e4f-4f31-b8a8-2d42fcf41104?imageType=ws_icon_large");
    info1.sizeOnDisk = wstring(L"455 KB");

    SiteInfo info2;
    info2.name = wstring(L"Accounting - Contoso");
    info2.imageUrl = wstring(L"http://cdn.marketplaceimages.windowsphone.com/v8/images/bf05b44c-1e4f-4f31-b8a8-2d42fcf41104?imageType=ws_icon_large");
    info2.sizeOnDisk = wstring(L"768 MB");

    SiteInfo info3;
    info3.name = wstring(L"Marketing - Contoso");
    info3.imageUrl = wstring(L"http://cdn.marketplaceimages.windowsphone.com/v8/images/bf05b44c-1e4f-4f31-b8a8-2d42fcf41104?imageType=ws_icon_large");
    info3.sizeOnDisk = wstring(L"4.77 GB");

    m_siteInfoVector.push_back(info1);
    m_siteInfoVector.push_back(info2);
    m_siteInfoVector.push_back(info3);
}

int LocationsSyncingListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 3;
}

QVariant LocationsSyncingListModel::data(
        const QModelIndex &index,
        int role) const
{
    if (index.row() < 0 || index.row() >= rowCount(QModelIndex()))
    {
        return QVariant();
    }

    SiteInfo info = m_siteInfoVector.at(index.row());
    QString retVal;

    switch(role)
    {
    case name:
        retVal = QString::fromStdWString(info.name);
        break;
    case sizeOnDisk:
        retVal = QString::fromStdWString(info.sizeOnDisk);
        break;
    case imageUrl:
        retVal = QString::fromStdWString(info.imageUrl);
        break;
    }
    return retVal;
}

QHash<int, QByteArray> LocationsSyncingListModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[imageUrl] = "imageUrl";
    roles[sizeOnDisk] = "sizeOnDisk";
    roles[name] = "name";
    return roles;
}
