/**************************************************************************
** This file is part of LiteIDE
**
** Copyright (c) 2011-2016 LiteIDE Team. All rights reserved.
**
** This library is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License as published by the Free Software Foundation; either
** version 2.1 of the License, or (at your option) any later version.
**
** This library is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
** Lesser General Public License for more details.
**
** In addition, as a special exception,  that plugins developed for LiteIDE,
** are allowed to remain closed sourced and can be distributed under any license .
** These rights are included in the file LGPL_EXCEPTION.txt in this package.
**
**************************************************************************/
// Module: golangeditoption.cpp
// Creator: visualfc <visualfc@gmail.com>

#include "golangeditoption.h"
#include "ui_golangeditoption.h"
#include "golangedit_global.h"
//lite_memory_check_begin
#if defined(WIN32) && defined(_MSC_VER) &&  defined(_DEBUG)
     #define _CRTDBG_MAP_ALLOC
     #include <stdlib.h>
     #include <crtdbg.h>
     #define DEBUG_NEW new( _NORMAL_BLOCK, __FILE__, __LINE__ )
     #define new DEBUG_NEW
#endif
//lite_memory_check_end

GolangEditOption::GolangEditOption(LiteApi::IApplication *app,QObject *parent) :
    LiteApi::IOption(parent),
    m_liteApp(app),
    m_widget(new QWidget),
    ui(new Ui::GolangEditOption)
{
    ui->setupUi(m_widget);
    bool info = m_liteApp->settings()->value(GOLANGEDIT_MOUSEINFO,true).toBool();
    bool nav = m_liteApp->settings()->value(GOLANGEDIT_MOUSENAVIGATIOIN,true).toBool();
    ui->enableMouseInfoCheckBox->setChecked(info);
    ui->enableMouseNavigationCheckBox->setChecked(nav);
}

GolangEditOption::~GolangEditOption()
{
    delete m_widget;
    delete ui;
}

QWidget *GolangEditOption::widget()
{
    return m_widget;
}

QString GolangEditOption::name() const
{
    return "GolangEdit";
}

QString GolangEditOption::mimeType() const
{
    return OPTION_GOLANGEDIT;
}

void GolangEditOption::apply()
{
    bool info = ui->enableMouseInfoCheckBox->isChecked();
    bool nav = ui->enableMouseNavigationCheckBox->isChecked();
    m_liteApp->settings()->setValue(GOLANGEDIT_MOUSEINFO,info);
    m_liteApp->settings()->setValue(GOLANGEDIT_MOUSENAVIGATIOIN,nav);
}
