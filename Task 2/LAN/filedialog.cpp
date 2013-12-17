#include "filedialog.h"

FileDialog::FileDialog(QWidget *parent) :
    QWidget(parent), model(new QDirModel()), treeview(new QTreeView()),
    okButton(new QPushButton("OK")), pathField(new QLineEdit()), path("")

{
    treeview->setModel(model);
    QObject::connect(treeview, SIGNAL(clicked(QModelIndex)),
                     this, SLOT(getFileName(QModelIndex)));
    QObject::connect(okButton, SIGNAL(clicked()), this, SLOT(sendFileName()));
    QVBoxLayout *vlayout = new QVBoxLayout(this);
    this->setLayout(vlayout);
    vlayout->addWidget(treeview, 2);
    QHBoxLayout* hlayout = new QHBoxLayout();
    vlayout->addLayout(hlayout, 1);
    hlayout->addWidget(pathField, 2);
    hlayout->addWidget(okButton);
    this->setFixedSize(600, 400);

}

FileDialog::~FileDialog()
{
    delete treeview;
    delete model;
    delete pathField;
    delete okButton;
}

void FileDialog::getFileName(QModelIndex idx)
{
    if (model->isDir(idx))
        return;
    path = model->filePath(idx);
    pathField->setText(path);
}

void FileDialog::sendFileName()
{
    if (path != "")
    {
        emit fileName(path);
        this->close();
    }
}
