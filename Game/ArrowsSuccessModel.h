#pragma once
using namespace System::Drawing;
class ArrowsSuccessModel {
public:

	int width, height;
	int xCol, yCol;

	ArrowsSuccessModel(Image^ image, int xCol, int yCol) {
		width = image->Width / 4;
		height = image->Height / 1;
		this->xCol = xCol;
		this->yCol = yCol;
	}

	void drawSucccesArrow(Graphics^ graphic, Image^ image, int idSpriteX, int idSpriteY) {

		Rectangle rectangleVisible = Rectangle(this->width * idSpriteX, this->height * idSpriteY, this->width, this->height);
		graphic->DrawImage(image, this->xCol, this->yCol, rectangleVisible, GraphicsUnit::Pixel);
	}

};