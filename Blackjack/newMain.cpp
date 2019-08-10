//
//  newMain.cpp
//  CIS200Demo
//
//  Created by Jason Lu on 8/9/19.
//  Copyright © 2019 Jason Lu. All rights reserved.
//

#include <stdio.h>
#include "Table.h"
#include "Player(new).h"

int main(){
    int numPlayers;
    cout << "Number of Players: ";
    cin >> numPlayers;
    Table table(numPlayers);
    system ("pause");
    return 0;
}
