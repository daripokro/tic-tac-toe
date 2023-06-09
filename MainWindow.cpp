#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include "SettingsDialog.hpp"
#include "GameFieldDialog.hpp"

MainWindow::MainWindow( QWidget *parent )
    : QMainWindow( parent )
    , ui( new Ui::MainWindow )
{
    ui->setupUi(this);
    this->setWindowIcon( QIcon( ":/icons/Resources/appIcon.png" ) );
    QPixmap iconStart = QPixmap( ":/icons/Resources/start.png" );
    ui->startButton->setIcon( iconStart );
    ui->startButton->setIconSize( iconStart.rect().size() );
    QPixmap iconSettings = QPixmap( ":/icons/Resources/settings.png" );
    ui->settingsButton->setIcon( iconSettings );
    ui->settingsButton->setIconSize( iconSettings.rect().size() );

/* TODO::
 * * добавить красивый шрифт для текста
 * * возможность задать, изменять и отображать название команд
 * * настройки музыкального сопровождения
 * * сброс к дефолтным настройкам
 *
 * */

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_settingsButton_clicked()
{
    SettingsDialog dialog( this );
    dialog.exec();
}

void MainWindow::on_startButton_clicked()
{
    GameFieldDialog dialog( this );
    dialog.exec();
}
