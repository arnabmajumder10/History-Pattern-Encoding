#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

#include "ea_var.h"
#include "ea_struct.h"
#include "ea_class.h"
#include "ea_initialize.h"
#include "ea_extension.h"
#include "ea_menu.h"
#include "ea_access.h"
#include "ea_encoding.h"
#include "ea_coef.h"
#include "ea_access_encoded.h"
#include "ea_value_retrieval.h"
#include "ea_cost.h"

void ea :: opfile()
{
    char eaFile[100];

    sprintf(eaFile, "EA_%dD.txt", NO_OF_DIMENSION);

    if((fEA = fopen(eaFile, "wb+")) == NULL)
    {
        printf("\nCannot open file.\n");
    }
}

int main()
{
    ea A;

    A.opfile();
    outFile.open("Encoded.txt", std::ofstream::out | std::ofstream::trunc);
    outFile.close();
    outFile.open("Value.txt", std::ofstream::out | std::ofstream::trunc);
    outFile.close();

    A.ea_initialize(NO_OF_DIMENSION);

    A.ea_menu();

    return 0;
}
