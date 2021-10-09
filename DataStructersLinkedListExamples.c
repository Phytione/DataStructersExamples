#include <stdio.h>
#include <stdlib.h>


struct node{
	int data;
	struct node *next;
	
}*head;

//Ekrana bastýr
void EkranaBastir(){
  if(head==NULL){
  	printf("\nListede eleman yok");
  	return;
  }
  struct node*iter=head;
  while(iter!=NULL){
  	printf("%d\t",iter->data);
  	iter=iter->next;
  	
  	
  }
  

}
//Listeye veri ekle

void veriEkle(int deger){
	
	if(head==NULL){
		head=malloc(sizeof(struct node));
		head->data=deger;
		head->next=NULL;
	}
	else{
	 struct node*temp=head;
	 while(temp->next!=NULL){
	 	
	 	temp=temp->next;
	 	
	 	
	 }
	 temp->next=malloc(sizeof(struct node));
	 temp->next->data=deger;
	 temp->next->next=NULL;
	   	
	}
	
	
	
	
	
}
//Sona eleman ekleme
void sonaEkle(int deger){
	if(head==NULL){
		head=malloc(sizeof(struct node));
		head->data=deger;
		head->next=NULL;
	}
	else{
	struct node*iter=head;
	while(iter->next!=NULL){
		iter=iter->next;
		
	}

	iter->next=malloc(sizeof(struct node));
	iter=iter->next;
	iter->data=deger;
	iter->next=NULL;
	}
	
		
		
		
	}
	
//Baþa eleman ekleme
void BasaEkle(int deger){
	if(head==NULL){
		head=malloc(sizeof(struct node));
		head->data=deger;
		head->next=NULL;
	}
	else{
	
	struct node*iter=malloc(sizeof(struct node));
	iter->data=deger;
	iter->next=head;
	head=iter;	
	}
	
	
	
	
	
	
}	
//listedeki elemanlarý sayýyor
void elemanSay()
{
	int sayac=0;
	struct node*iter=head;
	while(iter!=NULL){
	iter=iter->next;	
	sayac++;	
	}
	
    printf("\nListedeki eleman sayisi:%d",sayac);
	
	
	
	}	
//Eleman arama	
void elemanAra(int aranan)
{
    struct node*iter=head;
    int bayrak =0;
    while(iter->next!=NULL)
	{
		if(iter->data==aranan)
		{
			printf("\nAradiginiz deger listede var\n");
			bayrak++;
			break;
		}
		iter=iter->next;
	}
	if(iter->data == aranan)
	{
		printf("\nAradiginiz deger listede var\n");
		bayrak++;
	}
	if(bayrak==0)
		printf("\nAradiginiz deger listede yok");	
}
//Ýlk elemaný silmek
void ilkElemaniSil(){
   if(head==NULL){
   	printf("Silinecek eleman yok");
   }
   else{
   	struct node*iter=head; 
    head=head->next; 
    printf("\nSilinen eleman:%d\n",iter->data);
    free(iter);
   }
   
   
}
	
//Verilen Bir düðümü silmek
void dugumSil(int deger)
{
	struct node*iter=head;
    int bayrak =0;
    if(head->data==deger){
    	
    	ilkElemaniSil();
		bayrak++;	
	}
	else
	{
		while(iter!=NULL)
		{
			if(iter->next->data==deger)
			{
				struct node*temp=iter->next;
				iter->next=iter->next->next;
				printf("\nSilinen eleman: %d\n\n",temp->data);
				free(temp);
				bayrak++;
				
				break;
			}
			
			else if(iter->next->next == NULL)
					printf("Silmek isteginiz deger listede yok");
			else
					iter=iter->next;
			
				
			
		}
	}
}
void islemler(){
	int islem,deger;
     while(1){
     	printf("\n 1-Listeye Veri Ekleme\n");
		printf(" 2-Basa Veri Ekleme\n");
		printf(" 3-Sona Veri Ekleme\n");
		printf(" 4-Listedeki Verileri Sayma\n");
		printf(" 5-Listedeki Bir Elemani silmek\n");
		printf(" 6-Listedeki Bir Elemani Arama\n");
		printf(" 7-Listenin Ilk elemanini silme\n");
		printf(" 8-Listeyi ekrana yazdir\n");
		printf(" 9-Cikis\n");
		printf("****Yapmak istediginiz islemi seciniz****: ",islem);	
			scanf("%d",&islem);
		if(islem==1){
			printf("\nEklemek istediginiz degeri giriniz: ",deger);
				scanf("%d",&deger);
					veriEkle(deger);
					 EkranaBastir();
		}
		else if(islem==2){
			printf("\nEklemek istediðiniz degeri giriniz: ",deger);
			    scanf("%d",&deger);
			         BasaEkle(deger);
			          EkranaBastir();
			         
		}
		else if(islem==3){
			printf("\nSona eklemek istediðiniz degeri giriniz: ",deger);
			    scanf("%d",&deger);
			         sonaEkle(deger);
			          EkranaBastir();
			         
		}
		else if(islem==4){
		    elemanSay();
			         
		}
		else if(islem==5){
			printf("\nSilmek istediginiz degeri girin: ",deger);
			    scanf("%d",&deger);
			          dugumSil(deger);
			          EkranaBastir();
			         
		}
		else if(islem==6){
			printf("\nAramak istediginiz degeri giriniz: ",deger);
			    scanf("%d",&deger);
			          elemanAra(deger);
			          EkranaBastir();
			         
		}
		else if(islem==7){
			  ilkElemaniSil();
			  EkranaBastir();
			         
		}
		else if(islem==8){
			  EkranaBastir();
			         
		}
		else if(islem==9){
			  printf("Programdan cikiliyor....");
			  break;
			         
		}
		else printf("***Lutfen gecerli bir deger giriniz!!***");
     	
     
     
     	
	 }
	
	
	
	
}
		
	
	

int main() {
	
	islemler();
	return 0;
}






