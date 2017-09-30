#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QPushButton>
#include <QStyle>
#include <QLabel>
#include <QMouseEvent>
#include <QTabBar>
#include <QStackedWidget>

#include "Tab.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Q_DISABLE_COPY(MainWindow)
    QWidget* centralWidget() const { return QMainWindow::centralWidget(); }
    void setCentralWidget(QWidget* w) { QMainWindow::setCentralWidget(w); }

    QWidget* _titleWidget;
    QLabel* _titleLabel;

    QTabBar* _tabWidget;
    QStackedWidget* _stackedWidget;

    QWidget* _mainWidget;

    QVBoxLayout* _centralLayout;

    QPoint _grabPos;

    static const size_t MARGIN = 1;

protected:
    bool event(QEvent* event);

    void mouseDoubleClickEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    Tab* insertTab(const QString& text, int pos = -1);
    void insertTab(const QString& text, Tab* tab, int pos = -1);
    void removeTab(int pos);
    void removeTab(Tab* tab);
    Tab* tabAt(int pos);

    QWidget* mainWidget() const;
    void setMainWidget(QWidget* w);

};

#endif // MAINWINDOW_H
