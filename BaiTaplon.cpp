#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h> 
typedef struct book_st{
	char ten[30];
	char theloai[30];
	int giatien; 
}Sach;

int Nhap(Sach *bookList ){
	int i;
	for( i=0; i<3; i++){
		printf("Nhap quyen sach %d:\n", i+1) ;
		printf("Ten: ");
		fflush(stdin);
		gets((bookList+i)->ten);
		printf("The loai: ");
		fflush(stdin);
		gets((bookList+i)->theloai);
		printf("Gia tien: ");
		scanf("%d",&(bookList+i)->giatien); 
	} 
} 

void Sapxep(Sach bookList[]){
//Sap xep theo the loai tu Z->A 
int i, j;
	for ( i= 0; i<2 ; i++) {
		for (  j=1; j<3; j++){
			if( strcmp((bookList[i]).theloai,bookList[j].theloai)==-1) {
			Sach t=bookList[i];
			bookList[i]=bookList[j];
			bookList[j]=t;
	  	    }
		} 
	}
	printf("STT||Ten                 ||The loai            ||Gia tien            \n");
	for ( i=0; i<3; i++){
		printf("%0.3d||%-20s||%-20s||%d\n",i+1,(bookList[i]).ten,(bookList[i]).theloai,(bookList[i]).giatien);  
	}
//Thong ke the loai sach 
	int t=0,x=0; 
	for(i=0; i<2; i++){
		if(strcmp(bookList[0].theloai,bookList[i+1].theloai)==0){
			t=t+1; 
		} 
	}
	for(j=2;j>0;j--){
		if(strcmp(bookList[2].theloai,bookList[j-1].theloai)==0) 
		x=x+1; 
	} 
	if(t==2){
	printf("%s co 3 quyen sach\n",bookList[0].theloai);
	}
	if(t==1){
		printf("%s co 2 quyen sach\n%s co 1 quyen sach\n",bookList[0].theloai,bookList[2].theloai); 
	} 
	 if(t==0){
		if(x==0){
			printf("%s co 1 quyen sach\n%s co 1 quyen sach\n%s co 1 quyen sach\n",bookList[0].theloai,bookList[1].theloai,bookList[2].theloai); 
		}
		if(x==1){
			printf("%s co 1 quyen sach\n%s co 2 quyen sach\n",bookList[0].theloai,bookList[2].theloai); 
		} 
	} 	
} 
void Ghivaotaptin(Sach *bookList){
	FILE *o = fopen("\\BaitapLon\\book.dat","wb");
	int i;
	  if(o == NULL) printf("Loi nhap file");
	  else {fwrite(bookList, sizeof(Sach),1,o);
	   
	  printf("\nNhap file thanh cong!");
	} fclose(o);
}
	
  
void Timkiem(Sach bookList[]){
	char Tentheloai[30];
	printf("Nhap the loai can tim vao: ");
	fflush(stdin);
	gets(Tentheloai);
	Sach book[3]; 
	int t=0,x=0;
	int i; 
	for( i = 0; i < 3; i++){
		if(strcmp(Tentheloai,bookList[i].theloai)==0){
	    t=t+1; 
	    book[x]=bookList[i];
	    x=x+1; 
		}
	}
	if(t==0) printf("Khong co quyen sach thuoc the loai nay\n"); 
	else{ 
	     printf("STT||Ten                 ||The loai            ||Gia tien            \n");
	     for( i=0; i<t; i++){
	     printf("%0.3d||%-20s||%-20s||%d\n",i+1,(book[i]).ten,(book[i]).theloai,(book[i]).giatien);	
         }
    }
}
void Menu(Sach bookList[]){
	system("cls");
	
	printf("\n\t==========================================MENU===================================================\n");
	printf("\t||1. Nhap du lieu cua tung quyen sach.                                                         ||\n");
	printf("\t||2. Sap xep, thong ke va hien thi thong tin chi tiet cua tung quyen sach theo the loai (Z->A).||\n");
	printf("\t||3. Tim quyen sach theo the loai.                                                             ||\n");
	printf("\t||4. Ghi vao tap tin nhi phan book.dat.                                                        ||\n");
	printf("\t||5. Thoat                                                                                     ||\n");
	printf("\t=================================================================================================\n");
	int x; 
	do {
		
	 printf(" \nNhap su lua chon: ");
     scanf("%d",&x); 
	switch(x) { 
		case 1:{
		    Nhap(bookList);
			getch(); 
			return Menu(bookList);
	   }
        case 2:{
        	Sapxep(bookList);
			getch();
			return Menu(bookList); 
		} 
		case 3:{
			Timkiem(bookList) ;
			getch();
			return Menu(bookList); 
		} 
		case 4:{
			Ghivaotaptin(bookList);
			getch(); 
			return Menu(bookList);
		} 
		case 5:{
			exit(0);
			break;
		} 
	    } 
		} while( x<=5);
} 
int main(){
	Sach *bookList= (Sach*) malloc ( 3* sizeof(Sach)) ;
	Menu(bookList);
	getch();
	free(bookList); 
}
