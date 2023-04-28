#include "DataClass.hpp"

std::vector< QString > DataClass::_defaultCellsTextVector = { "Понимание", "Высокая зп", "Успех"
                                                             , "Контроль за сотрудниками", "Хорошее настроение", "Отдых"
                                                            , "Досуг", "Вкусный кофе", "Печеньки",  };


QString DataClass::textFromCell( FieldData cellNumber )
{
    return _cellsTextVector.at( cellNumber );
}

void DataClass::resetToDefault()
{
    _cellsTextVector = _defaultCellsTextVector;
}
