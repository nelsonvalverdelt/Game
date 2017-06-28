#pragma once
#include <time.h>
#include <vector>
#include <stdlib.h>
#include "../Game.Models/ArrowsModel.h"
using namespace std;
using namespace System::Drawing;

class ArrowsController {
	vector<ArrowsModel> listArrowsColumn;

private:
	int posX = 0;
	int yCol1 = 0, xCol1 = 0,
		yCol2 = 0, xCol2 = 0,
		yCol3 = 0, xCol3 = 0,
		yCol4 = 0, xCol4 = 0;
	int idSpriteXCol1 = 0, idSpriteYCol1 = 0,
		idSpriteXCol2 = 0, idSpriteYCol2 = 0,
		idSpriteXCol3 = 0, idSpriteYCol3 = 0,
		idSpriteXCol4 = 0, idSpriteYCol4 = 0;

	bool outputArrowCol1 = false,
		 outputArrowCol2 = false,
		 outputArrowCol3 = false,
		 outputArrowCol4 = false;

	int randomCol1 = 0, randomCol2 = 0, randomCol3 = 0, randomCol4 = 0;

	int speed = 0,increaseSpeed = 0;
public:

	ArrowsController(){}

	//Alinear las flechas por columnbas en el eje X
	void alignArrowsPositionX(Graphics ^ graphic, Image^ image) {
		
		for (int i = 0; i < 4; i++)
		{
			int posX = 30 + (i * 120);
			ArrowsModel arrowModel = ArrowsModel(image, posX,0);
			listArrowsColumn.push_back(arrowModel);

		}
	}

	// Seteamos el nuevo incremento que nos devolvera desde nuestro formulario UIGame
	void setIncreaseSpeed(int increaseSpeed) {
		this->increaseSpeed = increaseSpeed;
	}

	// Nos devuelve el nuevo incremento utilizado
	int getIncreaseSpeed() {
		return this->increaseSpeed;
	}

	int moveArrows(Graphics^ graphic, Image^ image) {
		speed++;
		if (speed == 8) {
			speed = 0;
		}
			
		// COLUMNA 1
		if (yCol1 >= 550) {
			yCol1 = 0;
			outputArrowCol1 = false;
			idSpriteXCol1 = rand() % 3;
			idSpriteYCol1 = rand() % 3;
		}

		if (yCol1 == 0) {
			randomCol1 = rand() % 8 + 1;
		}

		if (speed == randomCol1) {
			outputArrowCol1 = true;
		}

		if (outputArrowCol1 == true) {
			yCol1 = yCol1 + getIncreaseSpeed();
			listArrowsColumn[0].drawRandomArrowColumn(graphic, image, yCol1,idSpriteXCol1, idSpriteYCol1);
		}


		// COLUMNA 2
		if (yCol2 >= 550) {
			yCol2 = 0;
			outputArrowCol2 = false;
			idSpriteXCol2 = rand() % 3;
			idSpriteYCol2 = rand() % 3;
		}

		if (yCol2 == 0) {
			randomCol2 = rand() % 8 + 1;
		}

		if (speed == randomCol2) {
			outputArrowCol2 = true;
		}

		if (outputArrowCol2 == true) {
			yCol2 = yCol2 + getIncreaseSpeed();
			listArrowsColumn[1].drawRandomArrowColumn(graphic, image, yCol2, idSpriteXCol2, idSpriteYCol2);
		}


		// COLUMNA 3
		if (yCol3 >= 550) {
			yCol3 = 0;
			outputArrowCol3 = false;
			idSpriteXCol3 = rand() % 3;
			idSpriteYCol3 = rand() % 3;
		}

		if (yCol3 == 0) {
			randomCol3 = rand() % 8 + 1;
		}

		if (speed == randomCol3) {
			outputArrowCol3 = true;
		}

		if (outputArrowCol3 == true) {
			yCol3 = yCol3 + getIncreaseSpeed();
			listArrowsColumn[2].drawRandomArrowColumn(graphic, image, yCol3, idSpriteXCol3, idSpriteYCol3);
		}


		// COLUMNA 4
		if (yCol4 >= 550) {
			yCol4 = 0;
			outputArrowCol4 = false;
			idSpriteXCol4 = rand() % 3;
			idSpriteYCol4 = rand() % 3;
		}

		if (yCol4 == 0) {
			randomCol4 = rand() % 8 + 1;
		}

		if (speed == randomCol4) {
			outputArrowCol4 = true;
		}

		if (outputArrowCol4 == true) {
			yCol4 = yCol4 + getIncreaseSpeed();
			listArrowsColumn[3].drawRandomArrowColumn(graphic, image, yCol4, idSpriteXCol4, idSpriteYCol4);
		}

		//Retornamos el incremento por pixeles actual
		return getIncreaseSpeed();
	}

};