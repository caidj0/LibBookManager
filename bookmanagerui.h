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
    void closeEvent(QCloseEvent * event);
    ~bookmanagerui();
public slots:
    void aboutus();
    void showregist();
    void regist();
    void back_to_homepage();
    void showlogin();
    void login();
    void showsettings();
    void showoperate();
    void logout();
    void delete_user();
    void change_username();
    void change_password();

private:
    Ui::bookmanagerui *ui;
};
#endif // BOOKMANAGERUI_H
