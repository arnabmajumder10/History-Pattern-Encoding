#define DSIZE 5000
#define NO_OF_DIMENSION 5
#define INITIAL_INPUT_ARRAY_LENGTH 1

FILE *fEA;

fstream File;
ofstream outFile;
ifstream inFile;

int *subarraySizeAll;
int *subscript;
int *calSubscript;
int *decodedSubscript;
int eaDimension;
int historyCount;
int *eaLengthOfDimension;
int indx = 0;
int CurrentSizeOfArray = 0;
