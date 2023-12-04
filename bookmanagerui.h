#ifndef BOOKMANAGERUI_H
#define BOOKMANAGERUI_H

#include <QMainWindow>
#include<QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class bookmanagerui;
}
QT_END_NAMESPACE

class bookmanagerui : public QMainWindow
{
    Q_OBJECT

public:
    bookmanagerui(QWidget *parent = nullptr);
    ~bookmanagerui();
public slots:
    void aboutus();
    void showregist();
    void regist();
    void regist_back();

private:
    Ui::bookmanagerui *ui;
};
#endif // BOOKMANAGERUI_H
