//Andrea Munoz Gris A01733058
// Dafne Linette Badillo Campuzano A01275298

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


struct mat{
	int col;
	int fil;
};

struct frac{
	int num;
	int den;	
};


struct frac suma(struct frac var, struct frac var1 ){
	struct frac n;
	n.num = (var.num * var1.den)+(var.den*var1.num);
	n.den = (var.den * var1.den);
	return n;
};

struct frac mcd(int num, int den){
  int mcd=2;
  if(den<0){
    num = num*(-1);
    den = den*(-1);
  }
  while(mcd<=abs(num) && abs(den)>=1){
    if ((num%mcd)==0 && (den%mcd)==0){
      num = (num/mcd);
      den = (den/mcd);
    }
    else{
        mcd++;
    }
  }
  struct frac a; 
  a.num = num; 
  a.den = den;
  return a;
}
struct frac multi(struct frac var, struct frac var1 ){
	struct frac n;
	n.num = var.num *var1.num;
	n.den = var.den *var1.den;
	return n;
};

void toString (struct frac a, int imp){
    int num = a.num; 
	int den = a.den;
    int c1=1;
    int c2=1;
    if (c1<imp){
        for(int i=c1; i<imp; i++)
        printf(" ");
    }printf("%d/", a.num);

    if(c2<imp){
        for(int j=c2; j<imp; j++)
        printf(" ");
  }printf("%d", a.den);
}



void llenar(struct mat matrix, struct frac *ptr){
	char num[1025];
	for(int i = 0; i<(matrix.fil*matrix.col); i++){
		//printf("Digit num \n");
		fgets(num, 1025, stdin);
      	(*(ptr+i)).num = atoi(num);
		//printf("Digit den \n");
      	fgets(num, 1025, stdin);
      	(*(ptr+i)).den = atoi(num);
            	
	}
}

int maxLength(struct mat matrix, struct frac *ptr){
  int numerador, denominador;
  int * arrLength = malloc((matrix.fil*matrix.col)* sizeof(int));
  for(int x=0; x<(matrix.fil*matrix.col); x++){
      numerador = (*(ptr+x)).num;
      denominador = (*(ptr+x)).den;
      int c1 = 1; int c2 = 1;
    if(c1>c2)
       *(arrLength+x) = c1;
    else
       *(arrLength+x) = c2;
  }
  int var_f = 1;
  for(int y=0; y<(matrix.fil*matrix.col); y++){
    if((*(arrLength+y))>var_f)
      var_f = *(arrLength+y);
  }
  return var_f;
}

struct frac *mult_mat( struct mat ma1, struct frac *m1, struct mat ma2, struct frac *m2, struct frac *m3 ){
    
    for(int i=0; i<ma1.fil; i++){
        for(int j=0; j<ma2.col; j++){
            struct frac s; 
            s.num = 0;
            s.den = 1;
            for (int x=0; x<ma1.col; x++){
                struct frac m = multi(*(m1+(ma1.col*i)+x), *(m2+(ma2.col*x)+j));
                s = suma(s, m);
      }*(m3+(ma2.col*i)+j) = mcd(s.num, s.den);
    }
  }
  return m3;
}


void mostrar(struct mat mat1,struct frac *ptr1, int imp){
	for(int i = 0; i<mat1.fil; i++){
		for (int j=0; j<mat1.col; j++){
			printf(" ");
            printf(" ");
			toString(*(ptr1+(mat1.col*i)+j), imp);
			printf(" ");
            printf(" ");
		}printf(" \n");
	}
}
void mostrar1(struct mat mat2, struct frac *ptr2 ,int imp){
	for(int i = 0; i<mat2.fil; i++){
		for (int j=0; j<mat2.col; j++){
			printf(" ");
            printf(" ");
			toString(*(ptr2+(mat2.col*i)+j), imp);
            printf(" ");
            printf(" ");
		}printf(" \n");
	}

}
void mostrar2(struct mat mat3, struct frac *ptr3,int imp){
	for(int i = 0; i<mat3.fil; i++){
		for (int j=0; j<mat3.col; j++){
			printf(" ");
            printf(" ");
			toString(*(ptr3+(mat3.col*i)+j), imp);
            printf(" ");
            printf(" ");
		}printf(" \n");
	}

}

int main()
{	

    int imp;
    int imp_resul; 
	char num[1025];
	struct mat ma1;
	struct mat ma2;
    
	printf("How many rows in the first matrix?\n");
    fgets(num,1025,stdin);
	ma1.fil = atoi(num);
    printf("How many colums in the first matrix?\n");
    fgets(num,1025,stdin);
	ma1.col = atoi(num);
	struct frac *m1 = malloc((ma1.fil*ma1.col)* sizeof(struct frac));

    printf("How many rows in the second matrix?\n");
    fgets(num,1025,stdin);
	ma2.fil = atoi(num);
    printf("How many colums in the second matrix?\n");
    fgets(num,1025,stdin);
	ma2.col = atoi(num);
	struct frac *m2 = malloc((ma2.fil*ma2.col)* sizeof(struct frac));

	if (ma1.fil==ma2.col){
		llenar(ma1,m1);
		llenar(ma2,m2);

        printf("\n"); 
		printf(" MATRIX 1\n");
		mostrar(ma1,m1,imp);
		printf("\n"); 
		printf(" X\n");
		printf("\n"); 
		printf(" MATRIX 2\n");
		mostrar1(ma2, m2, imp);
        printf("\n"); 
        printf(" =\n");
        printf("RESULT MATRIX\n");
        struct mat ma3;
        ma3.fil = ma1.fil;
        ma3.col = ma2.col;
        struct frac * m3 = malloc((ma1.fil*ma2.col)* sizeof(struct frac));
        struct frac *m3_r = mult_mat(ma1, m1, ma2, m2, m3);
        imp_resul = maxLength(ma3, m3_r);
        mostrar2(ma3, m3_r, imp_resul);
        printf("\n");
	}
	else{
		printf("The operation is impossible");
	}
	
	return 0;
}


