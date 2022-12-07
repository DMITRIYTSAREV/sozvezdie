#ifndef WIDGET_H
#define WIDGET_H

#include "figures.h"
#include "shapeitem.h"
#include "triangle.h"
#include "circle.h"
#include "square.h"
#include "QtGui/qicon.h"

#include <QWidget>
#include <QToolButton>
#include <QPainter>
#include <QVBoxLayout>
#include <QTimer>
#include <QDebug>



class MyButton : public QToolButton
{
    Q_OBJECT
private:
    QString figr;
public:
    MyButton(QString s ,QWidget* parent =nullptr);

signals:
    void myClicked(QString str);

public slots:
    void slotClicked();
};

class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    int updateButtonGeometry(QToolButton *button, int x, int y);
    void createShapeItem(const QPainterPath &path,
                         const QPoint &pos, const QColor &color);
    void moveItemRandom(ShapeItem &f);

    QPoint randomItemPosition();
    QColor randomItemColor();

    QToolButton *createToolButton(const QIcon &icon, QString str);

    QToolButton *newCircleButton;
    QToolButton *newSquareButton;
    QToolButton *newTriangleButton;

    QList<ShapeItem> shapeItems;

protected:
       void paintEvent(QPaintEvent *event) override;
       void resizeEvent(QResizeEvent *event) override;

private slots:
    void mySlot(QString str);
    void slotTimeout();

};
#endif // WIDGET_H
