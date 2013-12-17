#ifndef FILEDIALOG_H
#define FILEDIALOG_H

#include <QWidget>
#include <QDirModel>
#include <QTreeView>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

class FileDialog : public QWidget
{
    Q_OBJECT
public:
    explicit FileDialog(QWidget *parent = 0);
    ~FileDialog();

signals:
    bool fileName(QString);

public slots:
    void getFileName(QModelIndex idx);
    void sendFileName();
private:
    QDirModel* model;
    QTreeView* treeview;
    QLineEdit* pathField;
    QPushButton* okButton;
    QString path;

};

#endif // FILEDIALOG_H
