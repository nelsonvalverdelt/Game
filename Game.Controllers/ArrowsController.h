#pragma once
#include <time.h>
#include <vector>
#include <stdlib.h>
#include "../Game.Models/ArrowsModel.h"
#include "../Game.Models/ArrowsSuccessModel.h"

using namespace std;
using namespace System::Drawing;

class ArrowsController {
	vector<ArrowsModel> listArrowsColumn;
	vector<ArrowsSuccessModel> listArrowsSuccess;
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
#pragma region Lluvia de flechas

	//Alinear las flechas por columnbas en el eje X
	// En el eje Y lo alineamos en posicion cero del plano
	void alignArrowsPositionX(Image^ image) {

		for (int i = 0; i < 4; i++)
		{
			int posX = 30 + (i * 120);
			ArrowsModel arrowModel = ArrowsModel(image, posX, 0);
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

	// Lluvia de flechas
	int moveArrows(Graphics^ graphic, Image^ image) {
		speed++;
		if (speed == 30) {
			speed = 0;
		}

		// COLUMNA 1
		if (yCol1 >= 610) {
			yCol1 = 0;
			outputArrowCol1 = false;
			idSpriteXCol1 = rand() % 4;
			idSpriteYCol1 = rand() % 4;
		}

		if (yCol1 == 0) {
			randomCol1 = rand() % 30 + 1;
		}

		if (speed == randomCol1) {
			outputArrowCol1 = true;
			//Almacenar el Sprite con la direcció de la flecha
		}

		if (outputArrowCol1 == true) {
			yCol1 = yCol1 + getIncreaseSpeed();
			listArrowsColumn[0].drawRandomArrowColumn(graphic, image, yCol1, idSpriteXCol1, idSpriteYCol1);
		}


		// COLUMNA 2
		if (yCol2 >= 610) {
			yCol2 = 0;
			outputArrowCol2 = false;
			idSpriteXCol2 = rand() % 4;
			idSpriteYCol2 = rand() % 4;
		}

		if (yCol2 == 0) {
			randomCol2 = rand() % 29 + 1;
		}

		if (speed == randomCol2) {
			outputArrowCol2 = true;
			//Almacenar el Sprite con la direcció de la flecha
		}

		if (outputArrowCol2 == true) {
			yCol2 = yCol2 + getIncreaseSpeed();
			listArrowsColumn[1].drawRandomArrowColumn(graphic, image, yCol2, idSpriteXCol2, idSpriteYCol2);
		}


		// COLUMNA 3
		if (yCol3 >= 610) {
			yCol3 = 0;
			outputArrowCol3 = false;
			idSpriteXCol3 = rand() % 4;
			idSpriteYCol3 = rand() % 4;
		}

		if (yCol3 == 0) {
			randomCol3 = rand() % 29 + 1;
		}

		if (speed == randomCol3) {
			outputArrowCol3 = true;
			//Almacenar el Sprite con la direcció de la flecha
		}

		if (outputArrowCol3 == true) {
			yCol3 = yCol3 + getIncreaseSpeed();
			listArrowsColumn[2].drawRandomArrowColumn(graphic, image, yCol3, idSpriteXCol3, idSpriteYCol3);
		}


		// COLUMNA 4
		if (yCol4 >= 610) {
			yCol4 = 0;
			outputArrowCol4 = false;
			idSpriteXCol4 = rand() % 4;
			idSpriteYCol4 = rand() % 4;
		}

		if (yCol4 == 0) {
			randomCol4 = rand() % 29 + 1;
		}

		if (speed == randomCol4) {
			outputArrowCol4 = true;
			//Almacenar el Sprite con la direcció de la flecha
		}

		if (outputArrowCol4 == true) {
			yCol4 = yCol4 + getIncreaseSpeed();
			listArrowsColumn[3].drawRandomArrowColumn(graphic, image, yCol4, idSpriteXCol4, idSpriteYCol4);
			
		}


		//Retornamos el incremento por pixeles actual
		return getIncreaseSpeed();
	}

#pragma endregion

	int getCol1() {
		return this->yCol1;
	}
	int getCol2() {
		return this->yCol2;
	}
	int getCol3() {
		return this->yCol3;
	}
	int getCol4() {
		return this->yCol4;
	}

#pragma region Flechas de acertaciones

	void alignSuccessArrow(Image^ image) {
		for (int i = 0; i < 4; i++)
		{
			int posX = 0;
			posX = 30 + (i * 120);
			ArrowsSuccessModel arrowSuccessModel =  ArrowsSuccessModel(image,posX,550);
			listArrowsSuccess.push_back(arrowSuccessModel);
		}
	}

	void drawSuccessArrow(Graphics^ graphic, Image^ image) {

			// Seleccionamos una flecha segun el Sprite del eje X
			// En el eje Y del sprite lo dejamos en cero ya que solo contenemos solo una fila
			// Las flechas varian segun la posicion del Eje X
			listArrowsSuccess[0].drawSucccesArrow(graphic, image, this->idSpriteXCol1, 0);
			listArrowsSuccess[1].drawSucccesArrow(graphic, image, this->idSpriteXCol2, 0);
			listArrowsSuccess[2].drawSucccesArrow(graphic, image, this->idSpriteXCol3, 0);
			listArrowsSuccess[3].drawSucccesArrow(graphic, image, this->idSpriteXCol4, 0);

	}

#pragma endregion

#pragma region Acertacion

	int SuccessArrowUp(int idSpriteX, int idSpriteY) {

		char* color = new char[100];
		if (idSpriteYCol1 == 0) {
			color = "Flecha roja";
		}
		if (idSpriteYCol1 == 1) {
			color = "Flecha Azul";
		}
		if (idSpriteYCol1 == 2) {
			color = "Flecha Verde";
		}
		if (idSpriteYCol1 == 3) {
			color = "Flecha Amarillo";
		}

		if (this->idSpriteXCol1 == 3) {


		if (this->yCol1 > 540 && this->yCol1 < 560) {
			//Entonces almacena el sprite X y Y para obtener el color y ladirección de la flecha
				// Código aquí			
				return 1;
			}			
		}

		if (this->idSpriteXCol2 == 3) {
		if (this->yCol2 > 540 && this->yCol2 < 560) {
			//Entonces almacena el sprite X y Y para obtener el color y ladirección de la flecha
			// Código aquí	
				return 2;
			}
		}
		if (this->idSpriteXCol3 == 3) {

		if (this->yCol3 > 540 && this->yCol3 < 560) {
			//Entonces almacena el sprite X y Y para obtener el color y ladirección de la flecha
			// Código aquí		
			return 3;
			}
		}

		if (this->idSpriteXCol4 == 3) {
		if (this->yCol4 > 540 && this->yCol4 < 560) {
			//Entonces almacena el sprite X y Y para obtener el color y ladirección de la flecha
			// Código aquí
			return 4;
			}
		}

		return 0;

	}

	bool SuceesArrowDown() {


		if (this->yCol2 == 550) {
			//Entonces almacena el sprite X y Y para obtener el color y ladirección de la flecha
			// Código aquí
			return true;
		}
		return false;
	}
	bool SuceesArrowLeft() {

		if (this->yCol3 == 550) {
			//Entonces almacena el sprite X y Y para obtener el color y ladirección de la flecha
			// Código aquí

			return true;
		}
		return false;

	}
	bool SuceesArrowRight() {


		if (this->yCol4 == 550) {
			//Entonces almacena el sprite X y Y para obtener el color y ladirección de la flecha
			// Código aquí

			return true;
		}
		return false;

	}
	
#pragma endregion


};