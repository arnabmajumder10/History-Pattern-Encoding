void ea:: ea_menu()
{
    int choice;

    while(1)
    {
        cout << "\n1)Extend.";
        cout << "\n2)Coordinate Access.";
        cout << "\n3)Coordinate Access from Encoded Result.";
        cout << "\n4)Cost Calculation.";
        cout << "\n\n .......... Press 0 to break ..........";
        cout << "\n\nEnter Choice : ";
        cin >> choice;

        if(choice == 0)
        {
            fclose(fEA);
            break;
        }
        else
        {
            switch(choice)
            {
                case 1 :
                    ea_construct();
                    break;
                case 2 :
                    ea_access();
                    break;
                case 3 :
                    ea_access_encoded();
                    break;
                case 4 :
                    ea_cost();
                    break;
            }
        }
    }
}
