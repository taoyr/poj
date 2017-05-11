#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

static int aiNumber[100001] = {0};
static char acKeyPad[128] = {0};

void merge(int low, int mid, int high);
void merge_sort(unsigned int first, unsigned int last);
void storeInput(char[], int, int);
void init();
void output(int);

int main() {
    init();

    int num = 0;
    scanf("%d\n", &num);
    
    if (100000 < num || 0 >= num) {
        printf("No duplicates.\n");
        return -1;
    }

    for (int i = 0; i < num; i++) {
        char temp[1000] = {0};
        fgets(temp, 1000, stdin);
        //fprintf(stderr, "fgets stdin=%s\n", temp);

        storeInput(temp, 1000, i);
    }

	merge_sort(0, num - 1);

    output(num);
}

void output(int num) {
    bool isDup = false;

    for (int i = 0; i < num; i++) {
        int sum = 1;
        char temp1[16] = {0};
        char result[8] = {0};

        sprintf(temp1, "%d", aiNumber[i]);
        int len = strlen(temp1);

        if (len > 7) {
            return;
        }

        if (len < 7) {
            for (int k = 0; k < 7 - len; k++) {
                result[k] = '0';
            }
        }

        strcat(result, temp1);

        for (int j = i + 1; j < num; j++) {
            if (aiNumber[j] == aiNumber[i]) {
                sum++;
                i = j - 1;
                continue;
            } 

            i = j - 1;
            break;
        }

        if (2 > sum) {
            continue;
        }

        printf("%c%c%c-%c%c%c%c %d\n", result[0], result[1], result[2], result[3],
                result[4], result[5], result[6], sum);
        isDup = true;
    }

    if (!isDup) {
        printf("No duplicates.\n");
    }
}

void merge(int low, int mid, int high){
    int i, k;
    int *tmp = (int *)malloc((high-low+1)*sizeof(int));
    //申请空间，使其大小为两个
    int left_low = low;
    int left_high = mid;
    int right_low = mid + 1;
    int right_high = high;
    for(k=0; left_low<=left_high && right_low<=right_high; k++){  // 比较两个指针所指向的元素
        if(aiNumber[left_low]<=aiNumber[right_low]){
            tmp[k] = aiNumber[left_low++];
        }else{
            tmp[k] = aiNumber[right_low++];
        }
    }
    if(left_low <= left_high){  //若第一个序列有剩余，直接复制出来粘到合并序列尾
    //memcpy(tmp+k, aiNumber+left_low, (left_high-left_low+l)*sizeof(int));
    for(i=left_low;i<=left_high;i++)
        tmp[k++] = aiNumber[i];
    }
    if(right_low <= right_high){
    //若第二个序列有剩余，直接复制出来粘到合并序列尾
    //memcpy(tmp+k, aiNumber+right_low, (right_high-right_low+1)*sizeof(int));
        for(i=right_low; i<=right_high; i++)
            tmp[k++] = aiNumber[i];
    }
    for(i=0; i<high-low+1; i++)
        aiNumber[low+i] = tmp[i];
    free(tmp);
    return;
}

void merge_sort(unsigned int first, unsigned int last){
    int mid = 0;
    if(first<last){
        mid = (first+last)/2; /* 注意防止溢出 */
        /*mid = first/2 + last/2;*/
        //mid = (first & last) + ((first ^ last) >> 1);
        merge_sort(first, mid);
        merge_sort(mid+1,last);
        merge(first,mid,last);
    }
    return;
}

void init() {
    acKeyPad['0'] = '0';
    acKeyPad['1'] = '1';
    acKeyPad['2'] = acKeyPad['A'] = acKeyPad['B'] = acKeyPad['C'] = '2';
    acKeyPad['3'] = acKeyPad['D'] = acKeyPad['E'] = acKeyPad['F'] = '3';
    acKeyPad['4'] = acKeyPad['G'] = acKeyPad['H'] = acKeyPad['I'] = '4';
    acKeyPad['5'] = acKeyPad['J'] = acKeyPad['K'] = acKeyPad['L'] = '5';
    acKeyPad['6'] = acKeyPad['M'] = acKeyPad['N'] = acKeyPad['O'] = '6';
    acKeyPad['7'] = acKeyPad['P'] = acKeyPad['R'] = acKeyPad['S'] = '7';
    acKeyPad['8'] = acKeyPad['T'] = acKeyPad['U'] = acKeyPad['V'] = '8';
    acKeyPad['9'] = acKeyPad['W'] = acKeyPad['X'] = acKeyPad['Y'] = '9';
}

void storeInput(char numOrigin[], int length, int index) {
    char temp[1000] = {0};

    for (int i = 0, j = 0; i < length; i++) {
        if (numOrigin[i] == 0) {
            break;
        }

        if (numOrigin[i] == '-' || numOrigin[i] == 'Q' || numOrigin[i] == 'Z') {
            continue;
        }

        if (numOrigin[i] < 0) {
            return;
        }

        temp[j] = acKeyPad[numOrigin[i]];
        j++;
    }

    if (strlen(temp) != 7) {
        return;
    }

    aiNumber[index] = atoi(temp);
    //fprintf(stderr, "aiNumber[%d]=%d\n", index, aiNumber[index]);
}
