// window.h

#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QSlider>

namespace Ui {
class Window;
}

class Window : public QWidget
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);
    ~Window();

public slots:
	void radioButtonChanged();

protected:
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::Window *m_ui;
};

#endif // WINDOW_H
