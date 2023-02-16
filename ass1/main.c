#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#include <stdint.h>

enum State {WORKING = 1, FAILED = -1};
int g_Array[];

int main() {
    char choose;
    int arrSize;
    do {
        printf("\n'c' Tao mang so nguyen");
		printf("\n'p' In day");
		printf("\n'i' Them phan tu vao day tai vi tri k");
		printf("\n'd' Xoa phan tu tai vi tri k");
		printf("\n's' Sap xep day so tang dan");
		printf("\n'x' Sap xep day so giam dan");
		printf("\n't' Tim kiem");
		printf("\n'e' Thoat");
		printf("\nChon: ");
		scanf("%c", &choose);

		switch (choose) {
            case 'c': {
                    printf("Nhap so luong phan tu: ");
                    scanf("%d", &arrSize);
                    if (initArray(arrSize) != FAILED) {
                        inputArray(g_Array, arrSize);
                    }
                    break;
            }
            case 'p': {
                    displayArray(g_Array, arrSize);
                    break;
            }
            case 'i': {
                    int position = 0;
                    int value = 0;
                    printf("Nhap vi tri can chen: ");
                    scanf("%d", &position);
                    printf("Nhap gia tri chan chen: ");
                    scanf("%d", &value);
                    addElement(g_Array, &arrSize, value, position);
                    printf("array size: %d", arrSize);
                    break;
            }
            case 'd': {
                    int position = 0;
                    printf("Nhap vi tri can xoa: ");
                    scanf("%d", &position);
                    deleteElement(g_Array, &arrSize, position);
                    printf("array size: %d", arrSize);
                    break;
            }
            case 's': {
                    sortAscArray(g_Array, arrSize);
                    break;
            }
            case 'x': {
                    sortDescArray(g_Array, arrSize);
                    break;
            }
            case 't': {
                    int value = 0;
                    printf("Nhap gia tri can tim: ");
                    scanf("%d", &value);
                    int result = searchArray(g_Array, arrSize, value);
                    if (result == WORKING) {
                        printf("gia tri can tim ton tai trong mang");
                    } else {
                        printf("gia tri can tim khong ton tai trong mang");
                    }
                    break;
            }
            case 'e': {
                    printf("\nThoat chuong trinh");
                    break;
            }
            default: {
                    printf("\nNhap ki tu de thuc hien chuong trinh");
                    break;
			}
        }
    } while (choose != 'e');
    return 0;
}
