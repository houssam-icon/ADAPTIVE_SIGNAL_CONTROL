#pragma once
#ifndef CAR_H
#define CAR_H

#include"raylib.h"
#include "draw.h"

enum class direction {

	UP , 
	DOWN ,
	LEFT , 
	RIGHT 
  
};

  
class car  { 
	 
private  : 
	  
	Vector2 pos;
	int height;
	int width;
	Color color; 
	direction d;
	int vitesse;
    
public :

	car(Vector2 position , direction dir) {
 
		pos = position;
		height = 50;
		width = 20;
		d = dir;
		vitesse = 50;
		color = RED;

	 }

	void acceleration() {
		 
		pos.x += vitesse;
		pos.y += vitesse;

	 }

	void stop(){

		vitesse = 0;

	}

	Vector2 actuallposition() {

		return pos;

	}

	void drawcars(){

		


	}

   };


#endif 

