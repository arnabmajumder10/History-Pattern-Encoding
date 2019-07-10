int ea :: ea_value_retrieval(int *sub)
{
    int i, j, sum = 0, prd = 1, address, value[1];

    for(i = eaDimension - 1; i >= 0; i--)
    {
        prd = sub[i];
        for(j = i - 1; j >= 0; j--)
        {
            prd *= eaLengthOfDimension[j];
        }
        sum += prd;
    }

    address = sum * sizeof(int);
    fseek(fEA, address, 0);
    fread(&value[0], sizeof(int), 1, fEA);

    return value[0];
}
