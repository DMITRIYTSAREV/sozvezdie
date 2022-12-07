#include "square.h"

Square::Square()
{
}

QPainterPath Square::getPath()
{
    return squarePath;
}

void Square::paintFigure()
{
   squarePath.addRect(QRect(0, 0, 100, 100));
}
