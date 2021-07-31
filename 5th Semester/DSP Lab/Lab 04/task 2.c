#include <stdio.h>

void crossProduct(int v_A[], int v_B[], int c_P[]) {
   c_P[0] = v_A[1] * v_B[2] - v_A[2] * v_B[1];
   c_P[1] = -(v_A[0] * v_B[2] - v_A[2] * v_B[0]);
   c_P[2] = v_A[0] * v_B[1] - v_A[1] * v_B[0];
}

int A[3] = { 7, 6, 4 };
int B[3] = { 2, 1, 3 };
int CrossProduct[3];
int main() {
   
   printf("Cross product:");
   crossProduct(A, B, CrossProduct);
   int i;
   for (i = 0; i < 3; i++)
      printf("%d ",CrossProduct[i]);
   return 0;
}
