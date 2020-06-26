#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h> 
typedef struct book_st{
	char ten[30];
	char theloai[30];
	int giatien; 
}Sach;

void Nhap(Sach *bookList ){
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
	for ( int i= 0; i<2 ; i++) {
		for (  int j=i; j<3; j++){
			if( strcmp((bookList[i]).theloai,bookList[j].theloai)==-1) {
			Sach t=bookList[i];
			bookList[i]=bookList[j];
			bookList[j]=t;
	  	    }
		} 
	}
	printf("STT||Ten                 ||The loai            ||Gia tien            \n");
	for ( int i=0; i<3; i++){
		printf("%0.3d||%-20s||%-20s||%d\n",i+1,(bookList[i]).ten,(bookList[i]).theloai,(bookList[i]).giatien);  
	}
//Thong ke the loai sach 
    int b[3];
    for(int i=0; i< 3; i++) b[i]=1;
    for (int i=0; i<3; i++){
    	if(b[i]==1){
    		b[i]=0;
    		int t=1;
    		for (int j=i+1; j<3;j++){
    			if(strcmp(bookList[i].theloai,bookList[j].theloai)==0){
    				t=t+1;
    				b[j]=0;
				}
			}
			printf("%s co %d quyen sach\n",bookList[i].theloai,t);
		}
	} 
}

void Ghivaotaptin(Sach *bookList){
	FILE *o = fopen("D:\\book.dat","wb");
	int i;
	  if(o == NULL) printf("Loi nhap file");
	  else {
	  for(int i=0; i<3; i++){
	  fwrite(bookList+i, sizeof(Sach),1,o);
	  }
	  printf("\nNhap file thanh cong!");
	 fclose(o);
}
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

void Menu(Sach bookList[], int t){
	system("cls");
	printf("\n\t============================================MENU=================================================\n");
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
		    t=1 ;
			getch();
			return Menu(bookList,t);
	   }
        case 2:{
        	if(t==1){
        	Sapxep(bookList);
        }
        else printf("Phai thuc hien su lua chon 1 truoc !\n"); 
			getch();
			return Menu(bookList,t);
		} 
		case 3:{
			if(t==1){
			Timkiem(bookList);
		}
		else printf("Phai thuc hien su lua chon 1 truoc !\n");
			getch();
			return Menu(bookList,t);
		} 
		case 4:{
			if(t==1){
			Ghivaotaptin(bookList);
		}else printf("Phai thuc hien su lua chon 1 truoc !\n");
			getch(); 
			return Menu(bookList,t);
		} 
		case 5:{
			exit(0);
			break;
		} 
	    } 
		} while( x<=5);
} 

int main(){
	Sach *bookList= (Sach*) malloc ( 3* sizeof(Sach));
	int t=0;
	Menu(bookList,t);
	getch();
	free(bookList); 
}
