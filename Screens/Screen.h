//
// Created by Belal on 25-Feb-25.
//

#ifndef SCREEN_H
#define SCREEN_H


#include <iostream>

using namespace std;
class Screen {
public:
    static void DrawScreen(string Head = "Screen") {
        system("cls");
        // cout<<"\t\t__________________________________________\n";
        //cout<<"\t\t\t"<<Head<<endl;
        //cout<<"\t\t__________________________________________\n";

        cout<<Head<<endl;
    }

};


#endif //SCREEN_H
