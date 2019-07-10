void ea :: ea_construct()
{
    int i, n;

    for(i = 0; i < eaDimension; i++)
    {
        printf("\nDimension%d: %d\n", i+1, i+1);
    }

    printf("\nExit : 0.\n\nEnter Choice: ");
    scanf("%d", &n);

    if(n > 0 && n <= eaDimension)
    {
        ea_extend(n - 1);
    }
}

void ea :: ea_extend(int n)
{
    int i, in, ind, var, temp, subarraySize, filePos;
    historyCount++;

    if(historyCount >= DSIZE)
    {
        printf("DSIZE Overflow.\n");
        exit(0);
    }

    subarraySize = 1;

    for(i = 0; i < eaDimension; i++)
    {
        subarraySize = subarraySize * pow(2, eaBoundaryVector[i].dimension[historyCount - 1].vectorElement);
    }

    CurrentSizeOfArray += subarraySize;

    eaExtended = (int*)malloc(subarraySize * sizeof(int));

    if(eaExtended == NULL)
    {
        printf("Memory Overflow : Extension\n");
        system("PAUSE");
    }
    else
    {
        subarraySizeAll[historyCount] = subarraySize; ///Store Sub-array Size at Each Extension
        extendedDimension[historyCount] = n; ///Store Extended Dimension at Each Extension

        for(i = 0; i < eaDimension; i++)
        {
            if(i == n)
                eaBoundaryVector[i].dimension[historyCount].vectorElement = eaBoundaryVector[i].dimension[historyCount - 1].vectorElement + 1;
            else
                eaBoundaryVector[i].dimension[historyCount].vectorElement = eaBoundaryVector[i].dimension[historyCount - 1].vectorElement;
        }

        eaTable[n].dimension[eaBoundaryVector[n].dimension[historyCount].vectorElement].historyValue = historyCount;
        eaLengthOfDimension[n] += pow(2, eaBoundaryVector[n].dimension[historyCount].vectorElement) - 1 - pow(2, (eaBoundaryVector[n].dimension[historyCount].vectorElement) - 1) + 1;
        eaTable[n].dimension[eaBoundaryVector[n].dimension[historyCount].vectorElement].coef = (int*)malloc((eaDimension - 2) * sizeof(int));

        ea_calCoefTable(n);

        ind = indx;

        for(in = 0; in < subarraySize; in = in + 5) ///Generate Random Values for Sub-array
        {
            if(in!=0)
                ind += 5;

            if(ind >= CurrentSizeOfArray)
                break;

            eaExtended[in] = rand() % 100;

            outFile.open("Value.txt", std::ios_base::app);
            outFile << "Value : " << eaExtended[in] << "\t" << "For Subscript : ";

            calSubscript[0] = ind % eaLengthOfDimension[0];
            var = (ind - calSubscript[0]) / eaLengthOfDimension[0];

            for(i = 1; i < eaDimension; i++)
            {
                if(i == 1)
                {
                    calSubscript[i] = (ind - calSubscript[0]) / eaLengthOfDimension[0] % eaLengthOfDimension[i];
                    var = var - calSubscript[i];
                }
                else if(i == eaDimension - 1)
                    calSubscript[i] = var / eaLengthOfDimension[i - 1];
                else
                {
                    temp = var / eaLengthOfDimension[i - 1];
                    calSubscript[i] = var / eaLengthOfDimension[i - 1] % eaLengthOfDimension[i];
                    var = temp - calSubscript[i];
                }
            }

            for(i = 0; i < eaDimension; i++)
                outFile << "D" << i + 1 << " : " << calSubscript[i] << "\t";
            outFile << endl;

            outFile.close();

            ea_encoding(calSubscript); ///Encode The Subscript Value
        }

        indx += subarraySize;

        fseek(fEA, (int)0, SEEK_END);
        filePos = ftell(fEA);
        fwrite(eaExtended, sizeof(int), subarraySize, fEA);
        free(eaExtended);

        eaTable[n].dimension[eaBoundaryVector[n].dimension[historyCount].vectorElement].firstAddress = filePos;

        for(i = 0; i < eaDimension; i++)
        {
            printf("Length D%d - %d\n",i + 1, eaLengthOfDimension[i]);
        }

        printf("History Count : %d", historyCount);
    }
}
