#ifndef MYTEXTEDIT_H
#define MYTEXTEDIT_H

#include <QTextEdit>
#include <QLineEdit>
#include <QKeyEvent>

class MyTextEdit: public QLineEdit
{
    Q_OBJECT
public:
    MyTextEdit();
signals:
    void removeEdge(int, int);
protected:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // MYTEXTEDIT_H



