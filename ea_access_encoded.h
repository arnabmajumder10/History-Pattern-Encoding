void ea :: ea_access_encoded()
{
    int i, j, var1 = 0, var2 = 0, index, maxHistory = 0, sum = 0, cnt = 0;
    char check;
    string binary, temp;

    printf("\nHighest Subscript for each dimension :\n\n");
    for(i = 0; i < eaDimension; i++)
    {
        printf("For : %d = %d   ||    ", i + 1, eaLengthOfDimension[i] - 1);
    }
    printf("\n\n");

    for(i = 0; i < eaDimension; i++)
    {
		printf("Enter subscript dimension %d : ", i + 1);
		scanf("%d", &subscript[i]);
    }

    for(i = 0; i < eaDimension; i++)
    {
        index = countBits(subscript[i]);

        if(maxHistory < eaTable[i].dimension[index].historyValue)
        {
            maxHistory = eaTable[i].dimension[index].historyValue;
        }
    }

    cout << "Max History : " << maxHistory << endl;

    int history;

    inFile.open("Encoded.txt");

    while(inFile >> history >> binary)
    {
        if(history == maxHistory)
        {
            check = binary[0];

            for(i = 0; i < eaDimension; i++)
            {
                if(check == '0')
                    var2 = 1;
                else
                    var2 = var1 + eaBoundaryVector[i].dimension[maxHistory].vectorElement;

                temp = binary.substr(var1, var2);

                for(j = 0; j < temp.size(); j++)
                {
                    if(temp[j] == '1')
                        sum += pow(2, (temp.size() - 1 - j));
                    else
                        sum += 0;
                }

                decodedSubscript[i] = sum;
                sum = 0;

                if(check == '0')
                    var1 = 1;
                else
                    var1 = eaBoundaryVector[i].dimension[maxHistory].vectorElement;

                check = '1';

                temp.clear();
            }
        }

        var1 = 0;
        var2 = 0;

        binary.clear();

        for(i = 0; i < eaDimension; i++)
        {
            if(subscript[i] == decodedSubscript[i])
                cnt++;
        }

        if(cnt == eaDimension)
            break;

        cnt = 0;
    }

    inFile.close();

    if(cnt == eaDimension)
    {
        for(i = 0; i < eaDimension; i++)
            cout << "D" << i + 1 << " : " << decodedSubscript[i] << "\t";

        printf("Value : %d", ea_value_retrieval(subscript));
    }
    else
        printf("Value : %d", ea_value_retrieval(subscript));
}
