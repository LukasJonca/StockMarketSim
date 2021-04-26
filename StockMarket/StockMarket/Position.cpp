#include "Position.h"

Position::Position(){
}

Position::Position(IAsset a, int q) {
	asset = a;
	quantity = q;
}

double Position::getVal(){
	return asset.getPrice() * quantity;
}
