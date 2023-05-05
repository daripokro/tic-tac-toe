#ifndef DATACLASS_HPP
#define DATACLASS_HPP

#include <vector>
#include <QString>

#include <QDebug>

typedef enum {
    Undefined = 0
    , One = 1
    , Two
    , Three
    , Four
    , Five
    , Six
    , Seven
    , Eight
    , Nine
} FieldData;


class DataClass
{
public:
    static DataClass& instance()
    {
        static DataClass _instance;
        return _instance;
    };
    void setTextForCell( FieldData cellNumber, QString text );
    QString textFromCell( FieldData cellNumber );
    void resetToDefault();

private:
    DataClass() = default;
    ~DataClass() {};

    static std::vector< QString > _defaultCellsTextVector;
    std::vector< QString > _cellsTextVector{ _defaultCellsTextVector };
};

#endif // DATACLASS_HPP
