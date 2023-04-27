#include "MainWindow.hpp"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap iconStart = QPixmap( ":/icons/Resources/start.png" );
    ui->startButton->setIcon( iconStart );
    ui->startButton->setIconSize( iconStart.rect().size() );
    QPixmap iconSettings = QPixmap( ":/icons/Resources/settings.png" );
    ui->settingsButton->setIcon( iconSettings );
    ui->settingsButton->setIconSize( iconSettings.rect().size() );
// TODO:: добавить шрифт для текста
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
