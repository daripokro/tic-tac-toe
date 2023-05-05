#include "DataClass.hpp"

std::vector< QString > DataClass::_defaultCellsTextVector = { "Понимание", "Высокая зп", "Успех"
                                                             , "Контроль за сотрудниками", "Хорошее настроение", "Отдых"
                                                            , "Досуг", "Вкусный кофе", "Печеньки",  };


void DataClass::setTextForCell( FieldData cellNumber, QString text )
{
    _cellsTextVector.at( cellNumber - 1 ) = text; // -1, т.к. нумерация в векторе с 0, а нумерация ячеек с 1
}

QString DataClass::textFromCell( FieldData cellNumber )
{
    return _cellsTextVector.at( cellNumber - 1 );
}

void DataClass::resetToDefault()
{
    _cellsTextVector = _defaultCellsTextVector;
}
