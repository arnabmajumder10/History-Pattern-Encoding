void ea :: ea_access()
{
    int i, j, sum = 0, prd = 1, address, value[1];

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

    for(i = eaDimension - 1; i >= 0; i--)
    {
        prd = subscript[i];

        for(j = i - 1; j >= 0; j--)
        {
            prd *= eaLengthOfDimension[j];
        }

        sum += prd;
    }

    address = sum * sizeof(int);
    fseek(fEA, address, 0);
    fread(&value[0], sizeof(int), 1, fEA);
    printf("\nAddress : %d    Value : %d", address, value[0]);
}
