
#pragma once

#include "QuickCutShared/Models/Action.h"

#include <QDialog>
#include "ui_ActionView.h"

class QShortcutInput;

class ActionView : public QDialog
{
    Q_OBJECT
public:
    enum WindowMode
    {
        ActionEdit   = 1,
        ActionCreate = 2
    };
    Q_ENUM(WindowMode)

private:
    ActionView(QWidget * parent, ActionView::WindowMode windowMode);

public:
    ActionView(QWidget * parent);
    ActionView(QWidget * parent, Action * action);
    ~ActionView();

    WindowMode getWindowMode();

private:
    void fillActionTypes();
    void fillEntries();
    void connectSlots();
    void updateVisibility(Action::ActionType type);

signals:
    void onSaved();
    void onCreated(Action * action);
    void onClosed();

public slots:

    void onTypeSelChange(int index);

    void onBtnKeyPlay(QShortcutInput * input, QPushButton * button);
    void onBtnFilePicker();
    void onBtnCancel();
    void onBtnSave();

private:
    Ui::ActionView * ui;

    Action * m_Action;

    WindowMode m_WindowMode;
};
