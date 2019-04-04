
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "ENIGME.h"

void intial (enigme *en ){
int i ;
for (i=0;i<3;i++){
en->selec[i]=0 ; 
}
en->Num_try = 0 ;
}

/*******************************************************/

void intialiser_en (enigme *en ){
en->t[0]= 0 ;
en->Num_en = rand()%6+1 ;
printf ("num = %d \n",en->Num_en);
 
en->posen[0]=getrect(12,185,551,108);
en->posen[1]=getrect(48,275,551,134);
en->posen[2]=getrect(13,404,551,96);
en->posg = getrect(0,0,600,500);
switch (en->Num_en){

case 1 : 
en->menueng = convpng("fichier enigme/enigme1/enigme1.png");
en->reponse[0]=convpng("fichier enigme/enigme1/enigme1reponse1.png");
en->reponse[1]=convpng("fichier enigme/enigme1/enigme1reponse2.png");
en->reponse[2]=convpng("fichier enigme/enigme1/enigme1reponse3.png");
break ;
case 2 :
en->menueng = convpng("fichier enigme/enigme1/enigme2.png");
en->reponse[0]=convpng("fichier enigme/enigme1/enigme2reponse1.png");
en->reponse[1]=convpng("fichier enigme/enigme1/enigme2reponse2.png");
en->reponse[2]=convpng("fichier enigme/enigme1/enigme2reponse3.png");
break; 
case 3 :
en->menueng = IMG_Load("fichier enigme/enigme2/enigme3.png");
en->posen[0]=getrect(12,185,551,108);
en->reponse[0]=convpng("fichier enigme/enigme2/enigme3reponse1.png");
en->reponse[1]=convpng("fichier enigme/enigme2/enigme3reponse2.png");
en->reponse[2]=convpng("fichier enigme/enigme2/enigme3reponse3.png");
break; 
case 4 :
en->menueng = IMG_Load("fichier enigme/enigme2/enigme4.png");
en->reponse[0]=convpng("fichier enigme/enigme2/enigme4reponse1.png");
en->reponse[1]=convpng("fichier enigme/enigme2/enigme4reponse2.png");
en->reponse[2]=convpng("fichier enigme/enigme2/enigme4reponse3.png");
break ;
case 5 :
en->menueng = IMG_Load("fichier enigme/enigme3/enigme5.png");
en->reponse[0]=convpng("fichier enigme/enigme3/enigme5reponse1.png");
en->reponse[1]=convpng("fichier enigme/enigme3/enigme5reponse2.png");
en->reponse[2]=convpng("fichier enigme/enigme3/enigme5reponse3.png");
break; 
case 6 :
en->menueng = IMG_Load("fichier enigme/enigme3/enigme6.png");
en->reponse[0]=convpng("fichier enigme/enigme3/enigme6reponse1.png");
en->reponse[1]=convpng("fichier enigme/enigme3/enigme6reponse2.png");
en->reponse[2]=convpng("fichier enigme/enigme3/enigme6reponse3.png");
break ;
}
}


int menigme(enigme  *en,stage *sta ){
int x,y,i ;
int static j ;
en->t[1]=0 ; 
SDL_Event eventt ;
SDL_BlitSurface(en->menueng,NULL,sta->fenetre,&en->posg);
SDL_PollEvent(&eventt);
switch(eventt.type){
case SDL_QUIT:
SDL_FreeSurface(en->reponse[0]);
SDL_FreeSurface(en->reponse[1]);
SDL_FreeSurface(en->reponse[2]);
break;
case SDL_MOUSEMOTION :

x=eventt.motion.x;
y=eventt.motion.y;
for (i=0;i<3;i++){
if (x>en->posen[i].x && x<en->posen[i].x+en->posen[i].w && y>en->posen[i].y && y<=en->posen[i].y+en->posen[i].h ){
if (!en->selec[i]){
en->selec[i]=1 ;
}
}else 
if (en->selec[i]){
en->selec[i]=0;
}
}
break ;
case SDL_MOUSEBUTTONDOWN :
 
x=eventt.button.x;
y=eventt.button.y;
for (i=0;i<3;i++){
if (x>en->posen[i].x && x<en->posen[i].x+en->posen[i].w &&  y>en->posen[i].y && y<=en->posen[i].y+en->posen[i].h ){
en->t[0]=1 ;
en->t[1]=1 ;
j=i;
}
}
break ;
}
if (en->t[1]==0 && en->t[0]==1){
 
return j ;
}
for (i=0;i<3;i++){
if (en->selec[i]){
SDL_BlitSurface(en->reponse[i],NULL,sta->fenetre,&en->posen[i]);
}
}
SDL_Flip(sta->fenetre);
return -1;
}


int reponse (enigme *en ,int j){
FILE *fic ;
int i ;
int x,y;
if (j!=-1){
fic = fopen ("fichier enigme/reponse.txt","r");
while (x!=en->Num_en){
 
fscanf (fic,"EnigmeNum = %d  =%d\n",&x,&i);
}
if (i==j){
fclose(fic);
return 1 ;
}else {
(en->Num_try)++;
fclose (fic);
return 0 ;
}
}
}

/****************************************/

void freeenigme(enigme *en){
int i; 
SDL_FreeSurface(en->menueng);
for(i=0;i<3;i++)
{SDL_FreeSurface(en->reponse[i];
}
}




for (i=0;i<3;i++){
SDL_FreeSurface(en->reponse[i]);
}
}
