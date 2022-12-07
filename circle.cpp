#include "circle.h"

Circle::Circle()
{

}

QPainterPath Circle::getPath()
{
    return circlePath;
}

void Circle::paintFigure()
{
    circlePath.addEllipse(QRect(0, 0, 100, 100));
}



