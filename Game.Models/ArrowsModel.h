#pragma once
#include <time.h>
#include <stdlib.h>

using namespace System::Drawing;
class ArrowsModel {
	int width, height;
	int xCol,yCol;

public:

	ArrowsModel(Image^ image, int xCol, int yCol) {
		width = image->Width / 4;
		height = image->Height / 4;
		this->xCol = xCol;
		this->yCol = yCol;
	}
	
	// Dibujamos la imagen
	void drawRandomArrowColumn(Graphics^ graphic, Image ^ image, int yCol, int idSpriteX, int idSpriteY) {

		// Nos permite seleccionar un segmento del sprite divido en 4 x 4, ésto pnos permitirá seleccionar una flecha
		Rectangle rectangleVisible = Rectangle(this->width * idSpriteX, this->height* idSpriteY, width, height);
		
		// xCol va a ser un parámetro definido en el contructor y va a ser constante en el eje X
		// yCol va a ser dinámico en el eje Y

		graphic->DrawImage(image, this->xCol, yCol, rectangleVisible, GraphicsUnit::Pixel);
	}


	
};