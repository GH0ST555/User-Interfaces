//
// Created by twak on 14/10/2019.
//

#include "responsive_window.h"
#include "responsive_layout.h"
#include "screenshot.h"
#include <iostream>
#include <QApplication>
#include <QScrollArea>


ResponsiveWindow::ResponsiveWindow() {

    setWindowTitle("2811: Coursework 1");
    setMinimumSize(320, 320);
    setMaximumSize(1280, 720);
    createWidgets();
}

void ResponsiveWindow::createWidgets() {

    ResponsiveLayout * rl = new ResponsiveLayout();
    //create a layout for scrollarea
    ResponsiveLayout * rl2 = new ResponsiveLayout();

    // add all the widgets we need to demonstrate all layouts
    //adding the extra widgets , created custom widgets etc.

    rl->addWidget(new ResponsiveLabel(kNavTabs));
    rl->addWidget(new ResponsiveLabel(kSearchButton));
    rl->addWidget(new ResponsiveLabel(kSignIn));
    rl->addWidget(new ResponsiveLabel(kSearchText));
    rl->addWidget(new ResponsiveLabel(kAdvert));
    rl->addWidget(new ResponsiveLabel(kShoppingBasket));
    rl->addWidget(new ResponsiveLabel(kSearchForward));
    rl->addWidget(new ResponsiveLabel(kSearchBackward));
    rl->addWidget(new ResponsiveLabel(kSearchOptions));
    rl->addWidget(new ResponsiveLabel(kHomeLink));
    rl->addWidget(new ResponsiveLabel(kOrderHistory));
    rl->addWidget(new ResponsiveLabel(kReigon));
    rl->addWidget(new ResponsiveLabel(kHelp));


    // for loop to initialize 17 search result images and descriptions
    for (int i = 0; i<17; i++){
        rl->addWidget(new ResponsiveLabel(kSearchResult));
        rl->addWidget(new ResponsiveLabel(KRText));

    }

    // note that later widgets are drawn on top of earlier widgets

    //create a scrollarea
    QScrollArea *area= new QScrollArea();
    //make sure the scrollarea is resizable
    area ->setWidgetResizable(true);
    //create a new widget
    QWidget * store = new QWidget();
    store ->setLayout(rl);
    rl2->addWidget(area);
    store->setMinimumHeight(1500);
    area->setWidget(store);
    setLayout(rl2);
}


