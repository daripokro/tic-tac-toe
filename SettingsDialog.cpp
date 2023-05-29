#include "SettingsDialog.hpp"
#include "ui_SettingsDialog.h"
#include "FillCellDialog.hpp"

SettingsDialog::SettingsDialog( QWidget *parent ) :
    QDialog(parent),
    ui( new Ui::SettingsDialog )
{
    ui->setupUi( this );
    this->setWindowIcon( QIcon( ":/icons/Resources/settings.png" ) );
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::on_button1_clicked()
{
    showDialog( FieldData::One );
}

void SettingsDialog::on_button2_clicked()
{
    showDialog( FieldData::Two );
}

void SettingsDialog::on_button3_clicked()
{
    showDialog( FieldData::Three );
}

void SettingsDialog::showDialog( FieldData number )
{
    FillCellDialog dialog( number, this );
    dialog.exec();
}

void SettingsDialog::on_button4_clicked()
{
    showDialog( FieldData::Four );
}

void SettingsDialog::on_button5_clicked()
{
    showDialog( FieldData::Five );
}

void SettingsDialog::on_button6_clicked()
{
    showDialog( FieldData::Six );
}

void SettingsDialog::on_button7_clicked()
{
    showDialog( FieldData::Seven );
}

void SettingsDialog::on_button8_clicked()
{
    showDialog( FieldData::Eight );
}

void SettingsDialog::on_button9_clicked()
{
    showDialog( FieldData::Nine );
}
