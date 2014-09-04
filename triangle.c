#include <stdio.h>

//number of lines triangles
int n;

int mat[30][30], L[30][30], R[30][30];

//File I/O
FILE *fin, *fout;

//protoypes
void readTriangle(const char *filename);
void displayTriangle();
void solve();
void write(const char *filename);

int main() {

    readTriangle("c:\\triangle.in");

    displayTriangle();

    solve();

    return(0);
}

void readTriangle(const char *filename) {

     fin = fopen(filename, "r");
     int i,j;

     fscanf(fin, "%d", &n);

     for(i=0;i<n;i++) {

         for(j=0;j<=i;j++) {

             fscanf(fin,"%d", &mat[i][j]);
         } 
     }     

     fclose( fin );
}


void write(const char *filename) {

     fout = fopen(filename, "w");

     int i,j;

     for(i=0;i<n;i++) {

         for(j=0;j<=i;j++) {

             fprintf(fout,"%d ", mat[i][j]);
         } 
             fprintf(fout, "\n");
     }     

}

void displayTriangle() {

     int i,j;

     for(i=0;i<n;i++) {

         for(j=0;j<=i;j++) {

             printf("%d ", mat[i][j]);
         } 
             printf("\n");
     }     

}

void solve() {

     int i,j;

     for(i=0;i<=n-1;i++) {

         L[n-1][i] = mat[n-1][i]; 
     }      

     for(i=n-2;i>=0;i--) {

         for(j=0;j<=i;j++) {

             if(mat[i][j] + L[i+1][j] > mat[i][j] + L[i+1][j+1]) {

                          L[i][j] = mat[i][j] + L[i+1][j]; 
                          R[i][j] = j;
             } else {

                          L[i][j] = mat[i][j] + L[i+1][j+1];
                          R[i][j] = j+1;
             }             
         }
     }

     i=0;

     j=0;

     write("triangle.out");

     printf("Road Solution:\n");
     fprintf(fout,"Road Solution:\n");

     while( i < n ) {

        printf("%d ",mat[i][j]); 
        fprintf(fout,"%d ",mat[i][j]); 

        j = R[i++][j];
     }

     fclose(fout);

}



