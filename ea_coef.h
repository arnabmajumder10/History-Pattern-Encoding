void ea :: ea_calCoefTable(int n)
{
    int prd = 1;
    int i, index = eaDimension - 3, var1, pos = n + 1, var;

    if(pos == NO_OF_DIMENSION)
        var = pos - 2;
    else
        var= NO_OF_DIMENSION - 1;

    var1 = var;

    for(i  = 0; i < NO_OF_DIMENSION - 2; i++)
    {
        prd = prd * eaLengthOfDimension[var1];
        var1--;

        if(var1 == n  && var1 != 0)
            var1--;

        eaTable[n].dimension[eaBoundaryVector[n].dimension[historyCount].vectorElement].coef[index] = prd;
        index--;

        if(index < 0)
            break;
    }

    cout << "\n\nCoef\n";
	for(i = 0; i < NO_OF_DIMENSION - 2; i++)
        cout << "\n"<< i + 1 << " : " << eaTable[n].dimension[eaBoundaryVector[n].dimension[historyCount].vectorElement].coef[i];
        cout << endl;
}
