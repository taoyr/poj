#include <stdio.h>
#include <stdlib.h>

//#define DEBUG

static float R = 0;
static int n = 0;
static int slotP = -1;
static int iRArray[7] = {0};
static int iRLen = 0;
static int iResultArray[150] = {0};
static int iResultLen = 0;

void exponentiation();
void deleteSlot(char *);
void addSlot();
void init();

void init() {
    R = 0;
    n = 0;
    slotP = -1;
    iResultLen = 0;
    iRLen = 0;
    for (int i = 0; i < 7; i++) {
        iRArray[i] = 0;
    }

    for (int i = 0; i < 150; i++) {
        iResultArray[i] = 0;
    }
}

int main() {
    char cTempArray[7] = {0};

    while (scanf("%f%d", &R, &n) != EOF) {
        if (R == 0) {
            printf("0\n");
            continue;
        }

        snprintf(cTempArray, 7, "%f", R);
        deleteSlot(cTempArray);
#ifdef DEBUG
        printf("cTempArray=%s\n", cTempArray);
        fflush(stdout);
#endif
        for (int i = 6, j = 0; i >= 0; i--) {
            if (cTempArray[i] != 0) {
                iRArray[j] = cTempArray[i] - '0';
                j++;
                iRLen = iResultLen = j;
            }
        }
#ifdef DEBUG
        for (int i = 0; i < iRLen; i++) {
            printf("iRArray[%d]=%d\n", i, iRArray[i]);
            fflush(stdout);
        }
#endif

        exponentiation();
        addSlot();

        if (iResultArray[0] == 0) {
            for (int i = 0; i < iResultLen; i++) {
                if (i >= slotP) {
                    break;
                }

                if (iResultArray[i] != 0) {
                    break;   
                }

                iResultArray[i] = -2;
            }
        }

        for (int i = iResultLen -1; i >= 0; i--) {
            if (iResultArray[i] == -2) {
                continue;
            } else if (iResultArray[i] == -1) {
                printf(".");
            } else {
                printf("%d", iResultArray[i]);
            }
        }

        printf("\n");
        init();
    }
}

void exponentiation() {
    int iTempResultArray[150] = {0}; 
    int iTempResultLen = 0;

    for (int i = 0; i < iResultLen; i++) {
        iTempResultArray[i] = iRArray[i];
        iTempResultLen = iRLen;
    }

    for (int k = 0; k < n - 1; k++) {
#ifdef DEBUG
        printf("k=%d, iRLen=%d, iTempResultLen=%d\n", k, iRLen, iTempResultLen);
        printf("iTempResultArray=");
        for (int i = iTempResultLen - 1; i >= 0; i--) {
            printf("%d", iTempResultArray[i]);
        }
        printf("\n");
        fflush(stdout);
#endif
        for (int i = 0; i < iRLen; i++) {
            for (int j = 0; j < iTempResultLen; j++) {
                iResultArray[i + j] = iTempResultArray[j] * iRArray[i] + iResultArray[i + j];
            }
        }

        int iResultMaxLen = iTempResultLen + iRLen;
        for (int i = iResultMaxLen; i >= 0; i--) {
            if (iResultArray[i] != 0) {
                iResultLen = i + 1;
            }
        }

        for (int i = 0; i < iResultMaxLen; i++) {
            iResultArray[i + 1] = iResultArray[i]/10 + iResultArray[i + 1];
            iResultArray[i] = iResultArray[i] % 10;
        }

        for (int i = 0; i < iResultMaxLen; i++) {
            iTempResultArray[i] = iResultArray[i];
            iResultArray[i] = 0;
        }

        for (int i = iResultMaxLen; i >= 0; i--) {
            if (iTempResultArray[i] != 0) {
                iResultLen = iTempResultLen = i + 1;
                break;
            }
        }
    }

    for (int i = 0; i < iTempResultLen; i++) {
        iResultArray[i] = iTempResultArray[i];
    }
#ifdef DEBUG
    printf("iResultArray=");
    for (int i = iResultLen - 1; i >= 0; i--) {
        printf("%d", iResultArray[i]);
    }
    printf("\n");
    fflush(stdout);
#endif
}

void deleteSlot(char* cArray) {
    for (int i = 5; i >= 0; i--) {
        slotP++;
        if(cArray[i] == '.') {
            for (int j = 5; j > i; j--) {   //delete 0 in the end
                if (cArray[j] != '0') {
                    break;
                } else {
                    slotP--;
                    cArray[j] = 0;
                }
            }

            for(int j = i; j < 6; j++) {    //move array without slot
                cArray[j] = cArray[j + 1];
            }

            for (int j = 0; j <= 6; j++) { //delete 0 in the front
                if (cArray[j] == 0) {
                    continue;
                } else if (cArray[j] == '0') {
                    cArray[j] = 0;
                    continue;
                } else {
                    break;
                }
            }

            return;
        }
    }

    slotP = 0;
}

void addSlot() {
    if (slotP == 0) {
        return;
    }

    iResultLen++;
    slotP = slotP * n;
#ifdef DEBUG
    printf("slotP=%d\n", slotP);
    fflush(stdout);
#endif
    if (slotP >= iResultLen) {
        for (int i = iResultLen - 1; i < slotP; i++) {
            iResultArray[i] = 0;
        }

        iResultArray[slotP] = -1;
        iResultLen = slotP + 1;

        return;
    }

    int temp = iResultArray[slotP];
    int temp2;
    iResultArray[slotP] = -1;

    for (int i = slotP + 1; i < iResultLen; i++) {
        temp2 = iResultArray[i];
        iResultArray[i] = temp;
        temp = temp2;
    }
#ifdef DEBUG
    printf("iResultArray=");
    for (int i = iResultLen - 1; i >= 0; i--) {
        printf("%d", iResultArray[i]);
    }
    printf("\n");
    fflush(stdout);
#endif
}
