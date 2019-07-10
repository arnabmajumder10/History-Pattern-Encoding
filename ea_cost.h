void ea :: ea_cost()
{
    int i;
    double hitoryTableCost = 0;
    double boundaryTableCost;

    for(i = 0; i < eaDimension; i++)
    {
        hitoryTableCost += ceil(1.0 * log2(eaLengthOfDimension[i]) + 1);
    }

    cout << "History Table Cost : " << hitoryTableCost << endl;

    for(i = 0; i < eaDimension; i++)
    {
        boundaryTableCost += ceil(1.0 * log2(eaLengthOfDimension[i]));
    }

    boundaryTableCost = eaDimension * (boundaryTableCost + 1);

    cout << "Boundary Table Cost : " << boundaryTableCost << endl;
}
