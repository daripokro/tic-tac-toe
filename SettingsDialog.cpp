#include "SettingsDialog.hpp"
#include "ui_SettingsDialog.h"
#include "FillCellDialog.hpp"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::on_button1_clicked()
{
    FillCellDialog dialog( FieldData::One, this );
}
