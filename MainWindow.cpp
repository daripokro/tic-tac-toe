#include "MainWindow.hpp"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap iconStart = QPixmap( ":/icons/Resources/start.png" );
    ui->pushButtonStart->setIcon( iconStart );
    ui->pushButtonStart->setIconSize( iconStart.rect().size() );
    QPixmap iconSettings = QPixmap( ":/icons/Resources/settings.png" );
    ui->pushButtonSettings->setIcon( iconSettings );
    ui->pushButtonSettings->setIconSize( iconSettings.rect().size() );
// TODO:: добавить шрифт для текста на кнопках  и вообще
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonSettings_clicked()
{

}

void MainWindow::on_pushButtonStart_clicked()
{

}
