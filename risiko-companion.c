#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int dado();
void tiro(int aa, int ad, int esito[2]);
void bubblesort(double x[], int N);

int main(){
  int aa, ad, ar;
  int esito[2]={};
  double armdopoconq[100]={};
  double armres[100]={};
  double armnoconq[100]={};
  int i, j;
  double w, l;
  double perarmdopoconq, perarmres, perarmnoconq;
  int aaM, adM, aaMt, adMt;
  printf("Armate in attacco: ");
  scanf("%d",&aa);
  printf("Armate in difesa: ");
  scanf("%d",&ad);
  printf("Attacchi finche' le armate sono almeno: ");
  scanf("%d",&ar);
  srand48(time(0));
  w=0;
  printf("\n0.........10........20........30........40........50........60........70.........80........90.......100\n");  

  for(j=1;j<1000000;j++){
    aaM=aa;
    adM=ad;
    if(j%9900==1)printf(".");
   
    while((aaM>=ar)&&(adM>0)&&(aaM>1)){
    esito[0]=0;
    esito[1]=0;  
    tiro(aaM, adM, esito);
    aaM-=esito[0];
    adM-=esito[1];
  };
 
  // printf("\naam %d, adm %d", aaM, adM);

  aaMt=aaM-1;
  adMt=adM-1;
  if(adM==0){
for(i=0;i<100;i++){
    if(aaMt==i)armdopoconq[i]+=1;
  };
 w+=1;
  };
  if(adM>0){
    for(i=0;i<100;i++){
  if(adMt==i)armres[i]+=1;
 };
for(i=0;i<100;i++){
    if(aaMt==i)armnoconq[i]+=1;
  };
  };
  // printf("\b\b");
  //printf("%2d", j/10000);
  };

  //  for(i=0;i<100;i++){
    // printf("\narmdopoconq%d= %lf\narmres%d= %lf", i, armdopoconq[i], i, armres[i]);
    //   printf("\ndado %d", dado());};

  w=w/10000;
  l=100-w;
  printf("\nL'attaccante conquista il territorio nel %.2lf%c dei casi", w, 37);
  printf("\n\nSe vince l'attaccante (%.2lf%c), questo rimane con: ", w, 37);
  for(i=1;i<aa+1;i++){
    perarmdopoconq=armdopoconq[i-1]/10000;
    printf("\n%d armate: %.2lf%c", i, perarmdopoconq, 37);
  };
  printf("\n\nSe il difensore resiste (%.2lf%c), l'attaccante rimane con: ", l, 37);
for(i=1;i<aa+1;i++){
    perarmnoconq=armnoconq[i-1]/10000;
    printf("\n%d armate: %.2lf%c", i, perarmnoconq, 37);
 };
 printf("\n\nMentre il difensore rimane con: ");
for(i=1;i<ad+1;i++){
    perarmres=armres[i-1]/10000;
    printf("\n%d armate: %.2lf%c", i, perarmres, 37);
 };


}

int dado(){
  int d=((lrand48()-1)/(double)RAND_MAX)*6+1;
  return d;
  }
void tiro(int aa, int ad, int esito[2]){
  double dadia [3];
  double dadid [3];
  double risultato[3];
  int i;
  if(aa==2){
    dadia[0]=dado();
    dadia[1]=0;
    dadia[2]=0;
  }else if(aa==3){
    dadia[0]=dado();
    dadia[1]=dado();
    dadia[2]=0;
  }else{
    dadia[0]=dado();
    dadia[1]=dado();
    dadia[2]=dado();
  };
if(ad==1){
  dadid[0]=dado()+0.5;
  dadid[1]=0;
  dadid[2]=0;
 }else if(ad==2){
  dadid[0]=dado()+0.5;
  dadid[1]=dado()+0.5;
  dadid[2]=0;
 }else{
  dadid[0]=dado()+0.5;
  dadid[1]=dado()+0.5;
  dadid[2]=dado()+0.5;
 };
 bubblesort(dadia, 3);
 bubblesort(dadid, 3);
 if(dadia[1]==0){
   dadid[1]=0;
   dadid[0]=0;
 }else if(dadia[0]==0)dadid[0]=0;
 if(dadid[1]==0){
   dadia[1]=0;
   dadia[0]=0;
 }else if(dadid[0]==0)dadia[0]=0;

 // printf("dadia %lf %lf %lf,   dadid %lf %lf %lf\n", dadia[0], dadia[1], dadia[2], dadid[0], dadid[1], dadid[2]);

 for(i=0;i<3;i++){
   risultato[i]=dadia[i]-dadid[i];
   if(risultato[i]>0){
esito[1]+=1;
   }else if(risultato[i]<0){
esito[0]+=1;
   }
 }
}
void bubblesort(double x[], int N){
  int i, j;
  double tmp;
  for(j=N-2; j>=0; j--){
    for(i=0; i<j+1; i++){
      if(x[i+1]<x[i]){
	tmp=x[i+1];
	x[i+1]=x[i];
	x[i]=tmp;
      }};};
}
