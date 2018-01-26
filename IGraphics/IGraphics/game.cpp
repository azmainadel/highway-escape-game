#include "iGraphics.h"
#include "gl.h"

double dx2=10+5,dy2,dx3=5+10,dy3,dx4=5+10,dX,dY;
double dlx1=15+5,dly,dlx2=15+5,dlx3=15+5,dlx4=15+5,dlx5=15+5;
double dnx2,dnx3,dnx4,dnlx1,dnlx2,dnlx3,dnlx4,dnlx5;
int scr_len=1000, scr_wid=600,l=170,w=90;
int score=0000,level=1,highscore;
char scorestr[4+1]={},levelstr[1+1]={},hsstr[4+1]={};
int x2=scr_len,x3=2*scr_len,x4=3*scr_len,X=l,y2=3*(w+9),y3=2*(w+9),Y=4*(w+9),y4=4*(w+9);
int flagC,flagS,flagB,flagI,flagX,flagG,flagGO,flagH;
int lx1=0,lx2=225,lx3=475,lx4=725,lx5=975;
int ly=w-5+(scr_wid/2),fy=w-100+(scr_wid/2);
int nitro=0,bx=2*scr_len+scr_len/3,by=2*(w+9)+w/2,dbx=30;
int arx=X+l-50,ary=Y+w/2,darx=50,dary,flaga;
FILE *fp1,*fp2;

int dif(int a, int b){
	return ((a-b)>=0)?(a-b):(b-a);
}

void iDraw(){
	iClear();
	iShowBMP(0,0,"pics\\cover.BMP");

	if(flagC==1){
		iClear();
		iShowBMP(0,0,"pics\\menu.BMP");
	}
	if(flagI==1){
		iClear();
		iShowBMP(0,0,"pics\\menu.BMP");
		iShowBMP(400,38,"pics\\ins.BMP");
	}
	if(flagB==1){
		iClear();
		iShowBMP(0,0,"pics\\menu.BMP");
	}
	if(flagH==1){
		iSetColor(0,0,0);
		iShowBMP(500,350,"pics\\highscore.BMP");
		iSetColor(255,0,0);
		iText(680, 380, hsstr, GLUT_BITMAP_TIMES_ROMAN_24);
	}
	if(flagS==1){
		iClear();
		if(level==1) iShowBMP(0,100,"pics\\lvl3.BMP");
		if(level==2) iShowBMP(0,100,"pics\\lvl2.BMP");
		if(level==3) iShowBMP(0,100,"pics\\lvl1.BMP");
		if(level==4) iShowBMP(0,100,"pics\\lvl6.BMP");
		if(level==5) iShowBMP(0,100,"pics\\lvl4.BMP");
		if(level==6) iShowBMP(0,100,"pics\\lvl5.BMP");
		iSetColor(55,60,68);
		iFilledRectangle(0,183,1000,320);
		//iShowBMP(0,183,"pics\\road.BMP");
		iSetColor(0,0,0);
		iFilledRectangle(0,175+328,1000,10);
		iFilledRectangle(0,175,1000,10);

		iShowBMP2(bx,by-35,"pics\\coin.BMP",255*65536+255*256+255);
		iShowBMP2(arx,ary-20,"pics\\bullet.BMP",255*65536+255*256+255);

		iSetColor(181,175,20);
		iFilledRectangle(lx1,ly,165,10);
		iFilledRectangle(lx2,ly,165,10);
		iFilledRectangle(lx3,ly,165,10);
		iFilledRectangle(lx4,ly,165,10);
		iFilledRectangle(lx5,ly,165,10);
		iFilledRectangle(lx1,fy,165,10);
		iFilledRectangle(lx2,fy,165,10);
		iFilledRectangle(lx3,fy,165,10);
		iFilledRectangle(lx4,fy,165,10);
		iFilledRectangle(lx5,fy,165,10);
		if (nitro == 1){
			iShowBMP2(X-54,Y,"pics\\redCarN.BMP",255*65536+255*256+255);
		}
		iShowBMP2(X,Y,"pics\\redCar.BMP", 255*65536+255*256+255);
		iShowBMP2(x2,y2,"pics\\greenCar.BMP",255*65536+255*256+255);
		iShowBMP2(x3,y3,"pics\\greenCar.BMP",255*65536+255*256+255);
		iShowBMP2(x4,y4,"pics\\greenCar.BMP",255*65536+255*256+255);

		iSetColor(255,255,255);
		iText(380, 50,"PRESS X TO SAVE AND EXIT", GLUT_BITMAP_HELVETICA_18);
		iText(413, 30,"PRESS END TO EXIT", GLUT_BITMAP_HELVETICA_18);
		iText(780, 50,"PRESS P TO PAUSE", GLUT_BITMAP_HELVETICA_18);
		iText(772, 30,"PRESS R TO RESUME", GLUT_BITMAP_HELVETICA_18);
		iText(50, 50,"YOUR SCORE : ", GLUT_BITMAP_HELVETICA_18);
		iText(50, 30,"YOU ARE IN LEVEL : ", GLUT_BITMAP_HELVETICA_18);
		
		iSetColor(255,0,0);
		iText(200, 50,scorestr, GLUT_BITMAP_HELVETICA_18);
		iText(230, 30,levelstr, GLUT_BITMAP_HELVETICA_18);
	}

	if(flagGO == 1){
		iDelay(1);
		iShowBMP(0,0,"pics\\gameOver.BMP");
		iSetColor(255,255,255);
		iText(380, 370,"YOUR FINAL SCORE : ", GLUT_BITMAP_HELVETICA_18);
		iSetColor(0,255,0);
		iText(580, 370,scorestr, GLUT_BITMAP_HELVETICA_18);

	}
}
void bonus(){
	if(((score%75==0 || (score-5)%75==0) && bx<-100) ||((X+l>=bx+25 && X<=bx+25) && (Y+w>=by-25 && Y<=by+25) ) ){
		bx= scr_len+(scr_len/3);
		by=(((rand()%3)+2)*(w+9)+w/2);
		if(bx==x2 || bx==x3 || bx==x4){
			bx=bx+2*w;
		}
	}
}

void iMouseMove(int mx, int my)
{
	//place your codes here
}
/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}
/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key){
	if(key == 'c'){
		flagC=1;
	}
	if(key == 'i'){
		flagI=1;
	}
	if(key == 's'){
		flagS=1;
		x2=scr_len;
		x3=scr_len;
	}
	if(key == 'b'){
		flagB=1;
	}
	if(key == 'h'){
		fp2 = fopen("files\\score.txt","r");
		fscanf(fp2,"%d",&highscore);
		fclose(fp2);
		flagH = 1;
	}
	if(key == 'x'){
		fp1 = fopen("files\\save.txt","w+");
		fprintf(fp1,"%d %d %d %d %d %d %d %d %s %s",X,Y,x2,y2,x3,y3,x4,y4,scorestr,levelstr);
		fclose(fp1);
		exit(0);
	}
	if(key=='a'){
		flaga=1;
	}
	if(key == 'd' && flagS==1){
		dx4=50;
		dx2=50;
		dx3=50;
		dlx1=55;dlx2=55;dlx3=55;dlx4=55;dlx5=55;
		dbx=50;
		nitro = 1;
	}
	if(key == 'w'){
		fp1 = fopen("files\\save.txt","r");
		fscanf(fp1,"%d %d %d %d %d %d %d %d %d %d",&X,&Y,&x2,&y2,&x3,&y3,&x4,&y4,&score,&level);
		fclose(fp1);
		flagS = 1;
	}
	if(key == 'p'){
		iPauseTimer(0);
		iPauseTimer(1);
		iPauseTimer(2);
	}
	if(key == 'r'){
		iResumeTimer(0);
		iResumeTimer(1);
		iResumeTimer(2);

	}
}
/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key){

	if(key == GLUT_KEY_UP && flagS==1 ){
		Y+=99;
	}
	if(key == GLUT_KEY_DOWN && flagS==1){
		Y-=99;
	}
	if(key == GLUT_KEY_LEFT){
		X-=50;
	}
	if(key == GLUT_KEY_RIGHT){
		X+=50;
	}
	if(key == GLUT_KEY_END){
		exit(0);
	}
}

void cars(){
	if(((X>=x2-dx2 && X<x2+dx2) || (X>=x3-dx3 && X<x3+dx3) || (X>=x4-dx4 && X<x4+dx4))) {
		score=(score+5);
	}
	if((X+l>=bx+25 && X<=bx+25) && (Y+w>=by-25 && Y<=by+25) && (flagS==1)){
			score+= 20;

	}

	if(x2<=-170 || y2<w || y2>(scr_wid-w)||(arx+50>=x2 && ary>y2 && ary<y2+w)){
		x2 = scr_len+l;
		y2 = ((rand()%3)+2)*(9+w);
		nitro = nitro*10;
		if((arx+50>=x2 && ary>y2 && ary<y2+w))
			flaga=0;
	}
		
	if(x3<=-170 || y3<w || y3>(scr_wid-w) || dif(x2,x3)<=2*w ||(arx+50>=x3 && ary>y3 && ary<y3+w) ){
		x3 = scr_len+(scr_len/2);
		y3 = ((rand()%3)+2)*(9+w);
		nitro = nitro*10;
		if((arx+50>=x3 && ary>y3 && ary<y3+w))
			flaga=0;
	}

	if(x4<=-170 || y4<w || y4>(scr_wid-w) || dif(x4,x3)<=2*w || dif(x2,x4)<=2*w || (arx+50>=x4 && ary>y4 && ary<y4+w)){
		x4 = scr_len+scr_len;
		y4 = ((rand()%3)+2)*(9+w);
		nitro = nitro*10;
		if((arx+50>=x4 && ary>y4 && ary<y4+w))
			flaga=0;
	}

	if(flaga==0){
		arx=X+l-50;
		ary=Y+w/2;
		flaga=0;
	}

	if(nitro==10000000){
		nitro=0;
	}

	if(lx1<=-250) lx1=scr_len;
	if(lx2<=-250) lx2=scr_len;
	if(lx3<=-250) lx3=scr_len;
	if(lx4<=-250) lx4=scr_len;
	if(lx5<=-250) lx5=scr_len;

}

void race(){
	if(score>=100 && score<300 && nitro == 0){
		dx2=15+5;dx3=15+5;dx4=15+5;dlx1=25;dlx2=20+5;dlx3=20+5;dlx4=20+5;dlx5=20+5;
		dbx = 30+5;
		level=2;
	}
	if(score>=300 && score<500 && nitro == 0){
		dx2=15+5+5;dx3=15+5+5;dx4=15+5+5;dlx1=20+5+5;dlx2=20+5+5;dlx3=20+5+5;dlx4=20+5+5;dlx5=20+5+5;
		dbx = 30+5+5;
		level=3;
	}
	if(score>=500 && score<800 && nitro == 0){
		dx2=15+5+5+5;dx3=15+5+5+5;dx4=15+5+5+5;dlx1=20+5+5+5;dlx2=20+5+5+5;dlx3=20+5+5+5;dlx4=20+5+5+5;dlx5=20+5+5+5;
		dbx = 30+5+5+5;
		level=4;
	}
	if(score>=800 && score<1400){
		dx2=15+5+5+5+10;dx3=15+5+5+5+10;dx4=15+5+5+5+10;dlx1=20+5+5+5+10;dlx2=20+5+5+5+10;dlx3=20+5+5+5+10;dlx4=20+5+5+5+10;dlx5=20+5+5+5+10;
		dbx = 30+5+5+10;
		level=5;
	}
	if(score>=1400 && score<2200){
		dx2=15+5+5+5+10+10;dx3=15+5+5+5+10+10;dx4=15+5+5+5+10+10;dlx1=20+5+5+5+10+10;dlx2=20+5+5+5+10+10;dlx3=20+5+5+5+10+10;dlx4=20+5+5+5+10+10;dlx5=20+5+5+5+10+10;
		dbx = 30+5+5+10+10;
		level=6;
	}
	x2 -= dx2;
	x3 -= dx3;
	x4 -= dx4;
	bx -= dbx;
	lx1 -= dlx1;
	lx2 -= dlx2;
	lx3 -= dlx3;
	lx4 -= dlx4;
	lx5 -= dlx5;

	if(flaga==1)
		arx += darx;

	if((X+l>=x2 && X<=x2+l) && ((Y+w>=y2 && Y<=y2+w) || (Y>=y2 && Y<=y2+w)) && (flagS==1)){
			iPauseTimer(0);
			iPauseTimer(1);
			iPauseTimer(2);
			flagGO=1;

			fp2=fopen("files\\score.txt","r");
			fscanf(fp2,"%d",&highscore);
			fclose(fp2);
			if(highscore<=score){
				highscore=score;
				fp2=fopen("files\\score.txt","w");
				fprintf(fp2,"%d",highscore);
				fclose(fp2);

			}
			PlaySound("sounds\\crash.wav",NULL,SND_ASYNC);

	}
	if((X+l>=x3 && X<=x3+l) && ((Y>=y3 && Y<=y3+w) || (Y+w>=y3 && Y<=y3+w)) && (flagS==1)){
			iPauseTimer(0);
			iPauseTimer(1);
			iPauseTimer(2);
			flagGO=1;

			fp2=fopen("files\\score.txt","r");
			fscanf(fp2,"%d",&highscore);
			fclose(fp2);
			if(highscore<=score){
				highscore=score;
				fp2=fopen("files\\score.txt","w");
				fprintf(fp2,"%d",highscore);
				fclose(fp2);

			}
			PlaySound("sounds\\crash.wav",NULL,SND_ASYNC);
	}
	if((X+l>=x4 && X<=x4+l) && ((Y>=y4 && Y<=y4+w) || (Y+w>=y4 && Y<=y4+w)) && (flagS==1)){
			iPauseTimer(0);
			iPauseTimer(1);
			iPauseTimer(2);
			flagGO=1;
			
			fp2=fopen("files\\score.txt","r");
			fscanf(fp2,"%d",&highscore);
			fclose(fp2);
			if(highscore<=score){
				highscore=score;
				fp2=fopen("files\\score.txt","w");
				fprintf(fp2,"%d",highscore);
				fclose(fp2);

			}
			PlaySound("sounds\\crash.wav",NULL,SND_ASYNC);
	}
	if(Y<2*(w+9) || Y>4*(w+9)){
			iPauseTimer(0);
			iPauseTimer(1);
			iPauseTimer(2);
			flagGO=1;

			fp2=fopen("files\\score.txt","r");
			fscanf(fp2,"%d",&highscore);
			fclose(fp2);
			if(highscore<=score){
				highscore=score;
				fp2=fopen("files\\score.txt","w");
				fprintf(fp2,"%d",highscore);
				fclose(fp2);

			}
			PlaySound("sounds\\crash.wav",NULL,SND_ASYNC);
	}

	levelstr[0]=(char)(level+48);
	scorestr[0]=(char)((score/1000)+48);
	scorestr[1]=(char)((score/100)%10+48);
	scorestr[2]=(char)((score/10)%10+48);
	scorestr[3]=(char)((score%10)+48);
	
	hsstr[0]=(char)((highscore/1000)+48);
	hsstr[1]=(char)((highscore/100)%10+48);
	hsstr[2]=(char)((highscore/10)%10+48);
	hsstr[3]=(char)((highscore%10)+48);
}

int main(){
	iSetTimer(25, bonus);
	iSetTimer(25, cars);
	iSetTimer(25, race);

	iInitialize(scr_len, scr_wid, "Highway Escape v1.0");
	return 0;
}