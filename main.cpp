
#include <QApplication>

#include <Controller/controller.h>
#include <View/view.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srand(0);
    auto myView=new View();
    myView->show();

    return a.exec();
}
