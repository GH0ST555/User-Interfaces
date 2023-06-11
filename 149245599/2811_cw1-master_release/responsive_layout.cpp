//
// Created by twak on 07/10/2019.
//

#include "responsive_layout.h"
#include "responsive_label.h"
#include <iostream>
#include <QScrollArea>

//using namespace std;


void ResponsiveLayout::setGeometry(const QRect &r /* our layout should always fit inside r */ ) {
    QLayout::setGeometry(r);
    //initialize counters for search result and result text
    //initialize height and width variables
    int cSr = 0;
    int cSr2= 0;
    int chT = r.y() + 165 + r.height()*0.06;
    int chT2 = r.y() + 170 + r.height()*0.11;
    int cwT = r.x() + 40;
    int ch = r.y() + 160;
    int cw = r.x() + 40;
    int cw2 = r.width()*0.15 +30;
    int cw2T =r.width()*0.15 +30;

    // for all the Widgets added in ResponsiveWindow.cpp
    for (int i = 0; i < list_.size(); i++) {

        QLayoutItem *o = list_.at(i);

        try {
            // cast the widget to one of our responsive labels
            ResponsiveLabel *label = static_cast<ResponsiveLabel *>(o->widget());
            //create a dynamic scrollarea
            QScrollArea *label2 = dynamic_cast<QScrollArea *>(o->widget());

            //if the scrollarea is null
            if (label2 != NULL){
                //set geometry for the scrollarea
                label2->setGeometry(r);
            }

            else if (label == NULL){ // null: cast failed on pointer
                std::cout << "warning, unknown widget class in layout" << std::endl;
            }


            //if the label is navtab, set appropriate location and dimensions
            else if (label -> text() == kNavTabs ){
                label -> setGeometry(0.21*r.width(),45+r.y(),r.width()*0.60, 40);
            }

            //if the label is search button set appropriate location and dimensions
            else if (label -> text() == kSearchButton ){
                label -> setGeometry(r.width()*0.59 + 10 ,r.y(),r.width()*0.19, 40);
            }


            //if the label is sign in button, set appropriate location and dimensions
            else if (label -> text() == kSignIn){
                label -> setGeometry(r.width()*0.78 + 20,0+r.y(),r.width()*0.21, 40);
            }

            //if the label is home button, set appropriate location and dimensions
            else if (label -> text() == kHomeLink){
                label -> setGeometry(r.width()*0.80,45+r.y(),r.width()*0.20, 40);
            }

            //if the label is search button, set appropriate location and dimensions
            else if (label -> text() == kSearchText){
                label -> setGeometry(r.x(),0+r.y(),r.width()*0.59, 40);
            }

            //if the label is Advert, set appropriate location and dimensions for horizontal layout
            else if (label -> text() == kAdvert && r.width()>600){
                label -> setGeometry(r.x(),160+r.y(),r.width()*0.15, r.height()- 160);
            }

            //if the label is search backwards button, set appropriate location and dimensions for compact layout
            else if (label -> text() == kSearchBackward && r.width()<600){
                label -> setGeometry(r.width()/2 -60,r.height() - 70,60, 30);
            }

            //if the label is search backwards button, set appropriate location and dimensions for horizontal layout
            else if (label -> text() == kSearchBackward && r.width()>600){
                label -> setGeometry(r.width()/2 -150,r.height() - 110,60, 50);
            }

            //if the label is search forward button, set appropriate location and dimensions for compact layout
            else if (label -> text() == kSearchForward && r.width()<600){
                label -> setGeometry(r.width()/2 +40,r.height() - 70,60, 30);
            }

            //if the label is search forward button, set appropriate location and dimensions for horizontal layout
            else if (label -> text() == kSearchForward && r.width()>600){
                label -> setGeometry(r.width()/2 +190,r.height() - 110,60, 50);
            }

            //if the label is search option , set appropriate location and dimensions
            else if (label -> text() == kSearchOptions){
                label -> setGeometry(r.x(),45+r.y(),0.30*r.width(), 40);
            }

            //if the label is shopping basket, set appropriate location and dimensions
            else if (label -> text() == kShoppingBasket){
                label -> setGeometry(0.25*r.width() + 10,90+r.y(),0.23*r.width(), 40);
            }

            //if the label is order history , set appropriate location and dimensions
            else if (label -> text() == kOrderHistory){
                label -> setGeometry(r.x(),90+r.y(),0.25*r.width(), 40);
            }

            //if the label is Reigon, set appropriate location and dimensions
            else if (label -> text() == kReigon){
                label -> setGeometry(0.49*r.width() + 30,90+r.y(),0.24*r.width(), 40);
            }

            //if the label is help, set appropriate location and dimensions
            else if (label -> text() == kHelp){
                label -> setGeometry(0.73*r.width() + 40,90+r.y(),0.25*r.width(), 40);
            }

            //if the label is search result, set appropriate location and dimensions for compact layout
            else if (label -> text() == kSearchResult && r.width ()< 600 ){
                //increase the counter value
                  cSr =cSr+1;
                 //sets the dynamic layout for the  first search result
                if (cSr == 1){
                    label -> setGeometry( r.x() + 40,
                                         r.y() + 160 ,r.width()*0.35, r.height()*0.06);
                }
                //sets the dynamic layout for the  rest of the search results
                else if (cSr>1){
                    //increase the xvalue dynamically
                    cw = cw +r.width()*0.35 + 10;
                    //check if the x value exceeds the width
                    if (cw + r.width()*0.35 + 10> r.width()){
                        //increase the height dynamically
                        ch = ch+r.height()*0.08+ 18 ;
                        //reset the value of the width to maintain a grid layout
                        cw = r.x() + 40;
                        //check if y value does not exceed the height and set result image
                        if (ch +r.height()*0.08 + 18 < r.height() -30 ){
                            label -> setGeometry( cw,ch, r.width()*0.35, r.height()*0.06);
                       }
                        else{
                           //hide the result image
                           label -> setGeometry( cw,ch, 0, 0);
                       }
                    }
                    else{
                        //check if the y value exceeds the height
                        if (ch +r.height()*0.08 + 18 > r.height() -30 ){
                            //hides the result image
                            label -> setGeometry( cw,ch, 0, 0);
                       }
                        else{
                         label -> setGeometry( cw,ch, r.width()*0.35, r.height()*0.06);

                        }

                    }
                }
            }

            //if the label is search result text, set appropriate location and dimensions for compact layout
            else if (label -> text() == KRText && r.width ()< 600 ){
                //increase the counter value
                cSr2 =cSr2+1;
                //sets the dynamic layout for the  first search result text
                if (cSr2 == 1){
                    label -> setGeometry( r.x() + 40,
                                         r.y() + 165 + r.height()*0.06 ,r.width()*0.35, r.height()*0.02);
                }
                //sets the dynamic layout for the  rest of the search result texts
                else if (cSr2>1){
                    //increase the xvalue dynamically
                    cwT = cwT +r.width()*0.35 + 10;
                    //check if the x value exceeds the width
                    if (cwT + r.width()*0.35 + 10> r.width()){
                        //increase the height dynamically
                        chT = chT+r.height()*0.08 + 18 ;
                        //reset the value of the width to maintain a grid layout
                        cwT = r.x() + 40;
                        //check if y value does not exceed the height and set result text
                        if (chT +r.height()*0.08 + 18 < r.height()  ){
                            label -> setGeometry( cwT,chT, r.width()*0.35, r.height()*0.02);
                       }
                        else{
                            //hide the result text
                           label -> setGeometry( cwT,chT, 0, 0);
                       }
                    }
                    else{
                        //check if the y value exceeds the height
                        if (chT +r.height()*0.08 + 18 > r.height() ){
                            label -> setGeometry( cwT,chT, 0, 0);
                        }
                        else{
                            //hides the result text
                         label -> setGeometry( cwT,chT, r.width()*0.35, r.height()*0.02);
                        }
                    }
                }
            }

            //if the label is search result  , set appropriate location and dimensions for horizontal layout
            else if (label -> text() == kSearchResult && r.width ()> 600 ){
                //increase the counter value
                cSr =cSr+1;
                //sets the dynamic layout for the  first search result image
                if (cSr == 1){
                    label -> setGeometry( r.width()*0.15 + 30,
                                         r.y() + 160, r.width()*0.19, r.height()*0.11);
               }
                //sets the dynamic layout for the  rest of the search result image
                else if (cSr>1){
                    //increase the xvalue dynamically
                    cw2 = cw2 +r.width()*0.19 + 10;
                    //check if the x value exceeds the width
                    if (cw2+ r.width()*0.19 + 10> r.width()){
                        //increase the height dynamically
                        ch = ch+r.height()*0.14 + 15 ;
                        //reset the value of the width to maintain a grid layout
                        cw2 = r.width()*0.15 + 30;
                        //check if y value does not exceed the height and set result
                        if (ch +r.height()*0.14 + 15 < r.height() - 40){
                            label -> setGeometry( cw2,ch, r.width()*0.19, r.height()*0.11);
                       }
                        else{
                             //hide the result image
                           label -> setGeometry( cw2,ch, 0, 0);
                       }
                    }
                    else{
                        //check if y value  exceeds the heighs
                        if (ch +r.height()*0.14 + 15 > r.height() - 40){
                            //hide the result image
                            label -> setGeometry( cw2,ch, 0, 0);
                       }
                        else{
                         label -> setGeometry( cw2,ch, r.width()*0.19, r.height()*0.11);
                        }

                    }
                }
            }

            //if the label is search result text, set appropriate location and dimensions for compact layout
            else if (label -> text() == KRText && r.width () > 600 ){
                //increase the counter value
                cSr2 =cSr2+1;
                if (cSr2 == 1){
                    label->setGeometry(r.width()*0.15 + 30,r.y() + 170 + r.height()*0.11 ,r.width()*0.19, r.height()*0.03);
                }
                //sets the dynamic layout for the  rest of the search result texts
                else if (cSr2>1){
                    //increase the xvalue dynamically
                    cw2T = cw2T+r.width()*0.19 + 10;
                    //check if the x value exceeds the width
                    if (cw2T + r.width()*0.19 + 10> r.width()){
                        //increase the height dynamically
                        chT2 = chT2+r.height()*0.14 + 15;
                        //reset the value of the width to maintain a grid layout
                        cw2T = r.width()*0.15 + 30;
                        //check if y value does not exceed the height and set result text
                        if (chT2 +r.height()*0.14 + 15 < r.height() ){
                            label -> setGeometry( cw2T,chT2, r.width()*0.19, r.height()*0.03);
                       }
                        else{
                           //hide the result text
                           label -> setGeometry( cw2T,chT2, 0, 0);

                       }
                    }
                    else{
                        //check if y value  exceeds the heighs
                        if (chT2 +r.height()*0.14 + 15 > r.height() ){
                            //hide the result text
                            label -> setGeometry( cw2T,chT2, 0, 0);
                       }
                        else{
                         label -> setGeometry( cw2T,chT2, r.width()*0.19, r.height()*0.03);
                        }
                    }
                }
            }
            else {// otherwise: disappear label by moving out of bounds
                label -> setGeometry (-1,-1,0,0);
            }

        }
        catch (std::bad_cast) {
            // bad_case: cast failed on reference...
            std::cout << "warning, unknown widget class in layout" << std::endl;
        }
    }
}

// following methods provide a trivial list-based implementation of the QLayout class
int ResponsiveLayout::count() const {
    return list_.size();
}

QLayoutItem *ResponsiveLayout::itemAt(int idx) const {
    return list_.value(idx);
}

QLayoutItem *ResponsiveLayout::takeAt(int idx) {
    return idx >= 0 && idx < list_.size() ? list_.takeAt(idx) : 0;
}

void ResponsiveLayout::addItem(QLayoutItem *item) {
    list_.append(item);
}

QSize ResponsiveLayout::sizeHint() const {
    return minimumSize();
}

QSize ResponsiveLayout::minimumSize() const {
    return QSize(320,320);
}

ResponsiveLayout::~ResponsiveLayout() {
    QLayoutItem *item;
    while ((item = takeAt(0)))
        delete item;
}
