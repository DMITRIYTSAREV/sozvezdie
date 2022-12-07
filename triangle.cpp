#include "triangle.h"

Triangle::Triangle()
{

}

QPainterPath Triangle::getPath()
{
    return trianglePath;
}

void Triangle::paintFigure()
{
    double x = trianglePath.currentPosition().x();
    double y = trianglePath.currentPosition().y();
    trianglePath.moveTo(x + 60, y);
    trianglePath.lineTo(0, 100);
    trianglePath.lineTo(120, 100);
    trianglePath.lineTo(x + 120 / 2, y);
}
