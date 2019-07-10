int *eaExtended;

struct Table
{
    int historyValue;
    int firstAddress;
    int *coef;
};

struct EATable
{
    struct Table dimension[DSIZE];
}*eaTable;

int *extendedDimension;

struct BoundaryVector
{
    int vectorElement;
};

struct EABoundaryVector
{
    struct BoundaryVector dimension[DSIZE];
}*eaBoundaryVector;
