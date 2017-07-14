#pragma once
#include <time.h>
#include <vector>
#include <stdlib.h>
#include "../Game.Views/ArrowsModel.h"
#include "../Game.Views/ArrowsSuccessModel.h"
#include <fstream>
using namespace std;
using namespace System::Drawing;

class ArrowsController {
	vector<ArrowsModel> listArrowsColumn1;
	vector<ArrowsModel> listArrowsColumn2;
	vector<ArrowsModel> listArrowsColumn3;
	vector<ArrowsModel> listArrowsColumn4;
	vector<ArrowsSuccessModel> listArrowsSuccess;
private:
	int yCol = 0;
	int yCol1 = 0, xCol1 = 0,
		yCol2 = 0, xCol2 = 0,
		yCol3 = 0, xCol3 = 0,
		yCol4 = 0, xCol4 = 0;
	int idSpriteXCol1 = 0, idSpriteYCol1 = 0,
		idSpriteXCol2 = 0, idSpriteYCol2 = 0,
		idSpriteXCol3 = 0, idSpriteYCol3 = 0,
		idSpriteXCol4 = 0, idSpriteYCol4 = 0;

	bool outputArrowCol = false;

	int randomCol1 = 0, randomCol2 = 0, randomCol3 = 0, randomCol4 = 0;

	int speed = 0, increaseSpeed = 0;
	int pixelY = 0;
	int posX=0, posY=0;
	int countArrowColumn1 = 0, countArrowColumn2 = 0, countArrowColumn3 = 0, countArrowColumn4 = 0;

	int indice = 0;
public:

	ArrowsController() {}
#pragma region Lluvia de flechas

	//Alinear las flechas por columnbas en el eje X
	// En el eje Y lo alineamos en posicion cero del plano
	void alignArrowsPositionX(Image^ image, int column) {

		// Parametro1: Seleccionamos la imagen del sprite
		// Parametro2: Seleccionamos la distancia de columnas
		// Parametro3: seleccionamos el sprite del eje X, el eje X en el sprite indica la dirección de la flecha
		ArrowsModel arrowModel1 = ArrowsModel(image, 30, 2);
		ArrowsModel arrowModel2 = ArrowsModel(image, 150, 3);
		ArrowsModel arrowModel3 = ArrowsModel(image, 270, 1);
		ArrowsModel arrowModel4 = ArrowsModel(image, 390, 0);

		switch (column)
		{
		case 1: listArrowsColumn1.push_back(arrowModel1); break;
		case 2: listArrowsColumn2.push_back(arrowModel2); break;
		case 3: listArrowsColumn3.push_back(arrowModel3); break;
		case 4: listArrowsColumn4.push_back(arrowModel4); break;
		}
	}

	void ArrowsRainColumn1(Graphics^ graphic, Image^ image) {
		
		for (int i = 0; i < listArrowsColumn1.size(); i++)
		{
				listArrowsColumn1[i].drawColumn(graphic, image);
				pixelY = listArrowsColumn1[i].getColY();
				pixelY++; //simulacion de movimiento por pixel
				listArrowsColumn1[i].setColY(pixelY);

				if (listArrowsColumn1[i].getColY() == 620) {
					listArrowsColumn1[i].setColY(750);
				}

				if (listArrowsColumn1[i].getColY() == 530) {
					countArrowColumn1 = i;
				}
		}	
	}

	void ArrowsRainColumn2(Graphics^ graphic, Image^ image) {

		for (int i = 0; i < listArrowsColumn2.size(); i++)
		{
			listArrowsColumn2[i].drawColumn(graphic, image);
			pixelY = listArrowsColumn2[i].getColY();
			pixelY++;
			listArrowsColumn2[i].setColY(pixelY);

			if (listArrowsColumn2[i].getColY() == 620) {
				listArrowsColumn2[i].setColY(750);
			}

			if (listArrowsColumn2[i].getColY() == 530) {
				countArrowColumn2 = i;
			}

		}
	}

	void ArrowsRainColumn3(Graphics^ graphic, Image^ image) {

		for (int i = 0; i < listArrowsColumn3.size(); i++)
		{
			listArrowsColumn3[i].drawColumn(graphic, image);
			pixelY = listArrowsColumn3[i].getColY();
			pixelY++;
			listArrowsColumn3[i].setColY(pixelY);

			if (listArrowsColumn3[i].getColY() == 620) {
				listArrowsColumn3[i].setColY(750);
			}

			if (listArrowsColumn3[i].getColY() == 530) {
				countArrowColumn3  = i;
			}

			
		}

	}

	void ArrowsRainColumn4(Graphics^ graphic, Image^ image) {

		for (int i = 0; i < listArrowsColumn4.size(); i++)
		{
			listArrowsColumn4[i].drawColumn(graphic, image);
			pixelY = listArrowsColumn4[i].getColY();
			pixelY++;
			listArrowsColumn4[i].setColY(pixelY);

			if (listArrowsColumn4[i].getColY() == 620) {
				listArrowsColumn4[i].setColY(750);
			}

			if (listArrowsColumn4[i].getColY() == 550) {
				countArrowColumn4 = i;
			}
		}
	}

#pragma endregion


#pragma region Flechas Inferiores Estáticas 

	void alignArrowsSuccess(Graphics^ graphic, Image^ image) {
		for (int i = 0; i < 4; i++)
		{
			posX = 30 + (i * 120);
			ArrowsSuccessModel arrowSuccess =  ArrowsSuccessModel(image,posX,550);
			listArrowsSuccess.push_back(arrowSuccess);
			listArrowsSuccess[i].drawSucccesArrow(graphic, image, i, 0);
		}
		
	}
#pragma endregion


	void SuceesArrowsLeft(int time) {
		//Verificamos si posición excede de la cantidad total de elementos almacenados en el vector
		if (countArrowColumn1 < listArrowsColumn1.size()) {
			
			// Intercalo  de aceptación al presionar la flecha
			if (listArrowsColumn1[countArrowColumn1].getColY() > 530 && listArrowsColumn1[countArrowColumn1].getColY() < 570) {
				listArrowsColumn1[countArrowColumn1].setColY(770);
				listArrowsColumn1[countArrowColumn1].setHit(true);
				listArrowsColumn1[countArrowColumn1].setTime(time);
			}
		}
	}

	void SuceesArrowsUp(int time) {

		//Verificamos si posición excede de la cantidad total de elementos almacenados en el vector
		if (countArrowColumn2 < listArrowsColumn2.size()) {

			// Intercalo  de aceptación al presionar la flecha
			if (listArrowsColumn2[countArrowColumn2].getColY() > 530 && listArrowsColumn2[countArrowColumn2].getColY() < 570) {
				listArrowsColumn2[countArrowColumn2].setColY(770);
				listArrowsColumn2[countArrowColumn2].setHit(true);
				listArrowsColumn2[countArrowColumn2].setTime(time);
			}
		}
	}
	
	void SuceesArrowsDown(int time) {

		//Verificamos si posición excede de la cantidad total de elementos almacenados en el vector
			if (countArrowColumn3 < listArrowsColumn3.size()) {

				// Intercalo  de aceptación al presionar la flecha
				if (listArrowsColumn3[countArrowColumn3].getColY() > 530 && listArrowsColumn3[countArrowColumn3].getColY() < 570) {

					listArrowsColumn3[countArrowColumn3].setColY(770);
					listArrowsColumn3[countArrowColumn3].setHit(true);
					listArrowsColumn3[countArrowColumn3].setTime(time);
					// indicamos que la flecha pasó
			}
		}
	
	

		
	}

	void SuceesArrowsRight(int time) {

		//Verificamos si posición excede de la cantidad total de elementos almacenados en el vector
		if (countArrowColumn4 < listArrowsColumn4.size()) {

			// Intercalo  de aceptación al presionar la flecha
			if (listArrowsColumn4[countArrowColumn4].getColY() > 530 && listArrowsColumn4[countArrowColumn4].getColY() < 570) {
				listArrowsColumn4[countArrowColumn4].setColY(770);
				listArrowsColumn4[countArrowColumn4].setHit(true);
				listArrowsColumn4[countArrowColumn4].setTime(time);
			}
		}
	}



#pragma region Guardar Datos Jugador

	void guardarJuego() {
		ofstream game;
		game.open("Game.txt");
		//game << "La lista de Pokebolas actual son:" << lista.size() << "\n";
		game << "Posición        Sprite        Acierto          Tiempo          Entrada\n";
		for (int i = 0; i < listArrowsColumn3.size(); i++) {

				bool inputArrow = listArrowsColumn3[i].getInputArrow();
				string color = validateColor(listArrowsColumn3[i].getSpriteY());
				string hit = validateHit(listArrowsColumn3[i].getHit());
				int time = listArrowsColumn3[i].getTime();

				game << "   " << i << "   ";
				game << "         " << color.c_str();
				game << "          " << hit.c_str();
				game << "          " << time;
				game << "          " << inputArrow << "\n";
			
		}
	}

#pragma endregion

#pragma region Validaciones

	string validateColor(int idSpriteY) {
	
		switch (idSpriteY)
		{
		case 0: return "rojo"; break;
		case 1: return "azul"; break;
		case 2: return "verde"; break;
		case 3: return "amarillo"; break;
		}
	}

	string validateHit(bool hit) {
		switch (hit)
		{
		case false: return "No";
		case true: return "Si";
		}
	}


#pragma endregion

	
};
