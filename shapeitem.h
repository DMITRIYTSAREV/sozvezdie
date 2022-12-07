#ifndef SHAPEITEM_H
#define SHAPEITEM_H

//#include "QtGui/qmatrix.h"
#include <QPainterPath>
#include <QColor>
class ShapeItem
{
   public:
       void setPath(const QPainterPath &path);
       void setPosition(const QPoint &position);
       void setColor(const QColor &color);

       QPainterPath path() const;
       QPoint position() const;
       QColor color() const;
   private:
       QPainterPath myPath;
       QPoint myPosition;
       QColor myColor;    
};

#endif // SHAPEITEM_H
