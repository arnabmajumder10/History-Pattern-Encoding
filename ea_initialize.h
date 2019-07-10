void ea :: ea_initialize(int totalDimension)
{
    int i;
    int filePos;
    int subarraySize;

    subarraySize = pow(INITIAL_INPUT_ARRAY_LENGTH, NO_OF_DIMENSION);
    CurrentSizeOfArray += subarraySize;
    historyCount = 0;
    eaDimension = totalDimension;

    eaTable = (struct EATable*)malloc(eaDimension * sizeof(struct EATable));

    if(eaTable == NULL)
    {
        printf("Memory Overflow : EATable.\n");
        exit(0);
    }

    eaBoundaryVector = (struct EABoundaryVector*)malloc(eaDimension * sizeof(struct EABoundaryVector));

    if(eaBoundaryVector == NULL)
    {
        printf("Memory Overflow : eaBoundaryVector.\n");
        exit(0);
    }

    extendedDimension = (int*)malloc(DSIZE * sizeof(int));

    if(extendedDimension == NULL)
    {
        printf("Memory Overflow : extendedDimension.\n");
        exit(0);
    }

    subarraySizeAll = (int*)malloc(DSIZE * sizeof(int));

    if(subarraySizeAll == NULL)
    {
        printf("Memory Overflow : subarraySizeAll.\n");
        exit(0);
    }

    subscript = (int*)malloc(eaDimension * sizeof(int));
    calSubscript = (int*)malloc(eaDimension * sizeof(int));
    decodedSubscript = (int*)malloc(eaDimension * sizeof(int));
    eaLengthOfDimension = (int*)malloc(eaDimension * sizeof(int));

    for(i = 0; i < eaDimension; i++)
    {
        eaTable[i].dimension[0].historyValue = historyCount;
        eaBoundaryVector[i].dimension[0].vectorElement = 0;
        eaTable[i].dimension[0].coef = (int*)malloc((eaDimension - 2) * sizeof(int));
    }

    extendedDimension[historyCount] = 0;

    eaExtended = (int*)malloc(subarraySize * sizeof(int));

    if(eaExtended == NULL)
    {
        printf("Memory Overflow : Initialization\n");
        exit(0);
    }
    else
    {
        for(i = 0; i < subarraySize; i++)
            eaExtended[i] = rand() % 100;

        outFile.open("Value.txt", std::ios_base::app);
        outFile << "Value : " << eaExtended[0] << "\t" << "For Subscript : ";

        for(i = 0; i < eaDimension; i++)
        {
            calSubscript[i] = 0;
            outFile << "D" << i + 1 << " : " << calSubscript[i] << "\t";
        }

        outFile << endl;
        outFile.close();

        ea_encoding(calSubscript); ///Encode The Subscript Value

        indx += subarraySize;

        subarraySizeAll[historyCount] = subarraySize;

        fseek(fEA, (int)0, 0);
        filePos = ftell(fEA);
        fwrite(eaExtended, sizeof(int), subarraySize, fEA);
        free(eaExtended);

        eaTable[0].dimension[0].firstAddress = filePos;

        for(i = 0; i < eaDimension; i++)
        {
            eaLengthOfDimension[i] = INITIAL_INPUT_ARRAY_LENGTH;
        }

        ea_calCoefTable(0);

        for(i = 0; i < eaDimension; i++)
        {
            printf("Length D%d - %d\n",i + 1, eaLengthOfDimension[i]);
        }

        printf("History Count : %d", historyCount);
    }
}
