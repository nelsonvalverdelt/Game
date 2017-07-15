#pragma once
#include <time.h>
#include <stdlib.h>

using namespace System::Drawing;
class ArrowsModel {
private:
	int width, height;
	int xCol, yCol;
	int idSpriteY, idSpriteX;
	bool outArrows = false;
	int count = 0;
	bool hit;
	int time;
	bool inputArrow;
public:

	ArrowsModel(Image^ image, int xCol, int idSpriteX) {
		this->width = image->Width / 4;
		this->height = image->Height / 4;
		this->yCol = 0;
		this->idSpriteY = rand() % 4;
		this->idSpriteX = idSpriteX;
		this->xCol = xCol;
		this->hit = false;
		this->time = 0;
		this->inputArrow = false;
	}

	bool getInputArrow() {
		return this->inputArrow;
	}
	void setInputArrow(bool inputArrow) {
		this->inputArrow = inputArrow;
	}

	int getTime() {
		return this->time;
	}

	void setTime(int time) {
		this->time = time;
	}
	bool getHit() {
		return this->hit;
	}

	void setHit(bool hit) {
		this->hit = hit;
	}
	int getColX() {
		return this->xCol;
	}

	void setColX(int xCol) {
		this->xCol = xCol;
	}

	int getColY() {
		return this->yCol;
	}
	void setColY(int yCol) {
		this->yCol = yCol;
	}

	int getSpriteY() {
		return this->idSpriteY;
	}
	int getSpriteX() {
		return this->idSpriteX;
	}

	void drawColumn(Graphics^ graphic, Image ^ image) {

			Rectangle rectangleVisible = Rectangle(this->width * idSpriteX, this->height * idSpriteY, width, height);
			graphic->DrawImage(image, this->xCol, this->yCol, rectangleVisible, GraphicsUnit::Pixel);
			if (this->getColY() > 530 && this->getColY() < 570) {
				this->inputArrow = true;
			}
	}

};