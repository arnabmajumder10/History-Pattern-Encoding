int countBits(int n)
{
	int count = 0;

	while(n)
	{
		count++;
		n = n>>1;
	}

	return count;
}

void ea :: ea_encoding(int *sub)
{
    int i, index, maxHistory = 0, j, n;
    string binary;
    string cpy;

    for(i = 0; i < eaDimension; i++)
    {
        index = countBits(sub[i]);

        if(maxHistory < eaTable[i].dimension[index].historyValue)
        {
            maxHistory = eaTable[i].dimension[index].historyValue;
        }

        n = sub[i];

        if(n == 0)
            cpy.push_back('0');
        else
        {
            while(n > 0)
            {
                j = n % 2;

                if(j == 1)
                    cpy.push_back('1');
                else
                    cpy.push_back('0');

                n = n / 2;
            }
        }

        for(int k = cpy.size() - 1; k >= 0; k--)
        {
                binary.push_back(cpy[k]);
        }

        cpy.clear();
    }

    outFile.open("Encoded.txt", std::ios_base::app);
    outFile << maxHistory << " " << binary << endl;
    outFile.close();
}
