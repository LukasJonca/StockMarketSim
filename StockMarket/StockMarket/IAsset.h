#pragma once

class IAsset {

public:
	
	
	virtual ~IAsset();
	virtual void movePrice(int days) = 0;
	

};
