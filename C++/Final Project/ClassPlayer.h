#include <SFML/Graphics.hpp>

using namespace std;


class PlyInfo {
	public:
		int tile, x, y, steps;
		bool status, pMove, adv;
		PlyInfo() {  tile = steps = 0; status = pMove = adv = false; }
		void setVect(PlyInfo*);
		bool checkWinner() { if(tile == 100)	return true;	return false; }
		friend bool checkTile(PlyInfo*);
		friend int plyrMove(PlyInfo*, PlyInfo*, PlyInfo*, PlyInfo*);
};

int plyrMove(PlyInfo *a, PlyInfo *b, PlyInfo *c, PlyInfo *d) {
	if(a->status) {
		if(a->pMove) {
      a->pMove = false;
      b->pMove = true;
      return 1;
		}
	}else
	if(b->status) {
		if(b->pMove) {
      b->pMove = false;
      return 2;
		}
		if(c->status)
			c->pMove = true;
		else
			a->pMove = true;
	}else
	if(c->status) {
		if(c->pMove) {
      c->pMove = false;
      return 3;
		}
		if(d->status)
			d->pMove = true;
		else
			a->pMove = true;
	}else
	if(d->status) {
		if(d->pMove) {
      d->pMove = false;
      a->pMove = true;
      return 4;
		}
	}
}

bool checkTile(PlyInfo * a) {
	a->adv = false;
	switch(a->tile) {
		//ladders
		case 1: a->tile = 38; a->adv = true;
            a->x = 12;  a->steps = 12;
            break;
		case 4: a->tile = 14; a->adv = true;
            a->x = 5;  a->steps = 10;
            break;
		case 9: a->tile = 31; a->adv = true;
            a->x = 20;  a->steps = 10;
            break;
		case 28: a->tile = 84;  a->adv = true;
            //a->w = 450;  a->z = 535;
            a->x = -20;  a->steps = 19;
            break;
		case 21: a->tile = 42;  a->adv = true;
             a->x =12;  a->steps = 7;
            //a->w = 55;  a->z = 440;
            break;
		case 51: a->tile = 67;  a->adv = true;
             a->x = -12;  a->steps = 11;
            //a->w = 570;  a->z = 280;
            break;
		case 71: a->tile = 91;  a->adv = true;
             a->x = -5;  a->steps = 8;
            //a->w = 585;  a->z = 145;
            break;
		case 80: a->tile = 100; a->adv = true;
             a->x = 5;  a->steps = 8;
            //a->w = 40;  a->z = 140;
            break;
		//snakes
		case 17: a->tile = 7;
             //a->w = 210;  a->z = 520;
             a->x = 400; a->y = 565;
             break;
		case 54: a->tile = 34;
             //a->w = 385;  a->z = 280;
             a->x = 395; a->y = 400;
             break;
		case 62: a->tile = 19;
             //a->w = 110;  a->z = 230;
             a->x = 110; a->y = 510;
             break;
		case 64: a->tile = 60;
             //a->w = 245;  a->z = 225;
             a->x = 40; a->y = 280;
             break;
		case 87: a->tile = 24;
             //a->w = 415;  a->z = 95;
             a->x = 225; a->y = 455;
             break;
		case 93: a->tile = 73;
             //a->w = 440;  a->z = 40;
             a->x = 455; a->y = 165;
             break;
		case 95: a->tile = 75;
            // a->w = 350;  a->z = 55;
             a->x = 350; a->y = 175;
             break;
		case 98: a->tile = 79;
             //a->w = 185;  a->z = 40;
             a->x = 120; a->y = 170;
             break;
		default: return false;
	}
	return true;
}
