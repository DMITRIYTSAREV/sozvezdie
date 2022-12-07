#include "widget.h"
#include "QtWidgets/qstyle.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    newCircleButton = createToolButton(QIcon(":/new/figures/circle.png"), "Circle");
    newSquareButton = createToolButton(QIcon(":/new/figures/square.jpeg"), "Square");
    newTriangleButton = createToolButton(QIcon(":/new/figures/triangle.png"), "Triangle");

    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Widget::slotTimeout);
    timer->setInterval(1000);
    timer->start();

    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(newCircleButton);
    pvbxLayout->addWidget(newSquareButton);
    pvbxLayout->addWidget(newTriangleButton);
    setLayout(pvbxLayout);

    setWindowTitle(tr("Tool Tips"));
    resize(500, 300);
}

Widget::~Widget()
{
}

int Widget::updateButtonGeometry(QToolButton *button, int x, int y)
{
    QSize size = button->sizeHint();
    button->setGeometry(x - size.rwidth(), y - size.rheight(),
                        size.rwidth(), size.rheight());

    return y - size.rheight()
           - style()->pixelMetric(QStyle::PM_DefaultLayoutSpacing);

}

void Widget::createShapeItem( const QPainterPath &path,const QPoint &pos, const QColor &color)
{
    ShapeItem shapeItem;

    shapeItem.setPath(path);
    shapeItem.setPosition(pos);
    shapeItem.setColor(color);
    shapeItems.append(shapeItem);
    update();
}

void Widget::moveItemRandom(ShapeItem &f)
{
    f.setPosition(randomItemPosition());
    update();
}

void Widget::slotTimeout()
{
    for(auto &f : shapeItems)
    {
        moveItemRandom(f);

    }
}

QPoint Widget::randomItemPosition()
{
    return QPoint(rand() % (width() - 120), rand() % (height() - 120));
}

QColor Widget::randomItemColor()
{
    return QColor::fromHsv(rand() % 256, 255, 190);
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    foreach (ShapeItem shapeItem, shapeItems) {
        painter.translate(shapeItem.position());
        painter.setBrush(shapeItem.color());
        painter.drawPath(shapeItem.path());
        painter.translate(-shapeItem.position());
    }
}

void Widget::resizeEvent(QResizeEvent *event)
{
   int margin = style()->pixelMetric(QStyle::PM_DefaultTopLevelMargin);
   int x = width() - margin;
   int y = height() - margin;

   y = updateButtonGeometry(newCircleButton, x, y);
   y = updateButtonGeometry(newSquareButton, x, y);

   updateButtonGeometry(newTriangleButton, x, y);
}

QToolButton *Widget::createToolButton(const QIcon &icon, QString str)
{
    MyButton *button = new MyButton(str);
    button->setIcon(icon);
    button->setIconSize(QSize(32, 32));

    connect(button, &MyButton::myClicked, this, &Widget::mySlot);

    return button;
}

MyButton::MyButton(QString s, QWidget *parent)
{
    figr = s;
    connect(this, &QToolButton::clicked, this, &MyButton::slotClicked);
}

void MyButton::slotClicked()
{
    emit myClicked(figr);
}

void Widget::mySlot(QString str)
{
    if (str == "Circle")
    {
        Figures* pCircle = new Circle();
        pCircle->paintFigure();
        createShapeItem(pCircle->getPath(), randomItemPosition(), randomItemColor());
    }
    else if(str == "Square")
    {
        Figures* pSquare = new Square();
        pSquare->paintFigure();
        createShapeItem(pSquare->getPath(),  randomItemPosition(), randomItemColor());
    }
    else if(str == "Triangle")
    {
        Figures* pTriangle = new Triangle();
        pTriangle->paintFigure();
        createShapeItem(pTriangle->getPath(), randomItemPosition(), randomItemColor());
    }
}
