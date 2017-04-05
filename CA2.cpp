#include<iostream>
#include<unistd.h> // for usleep
#include"GPIO.h"
using namespace exploringBB;
using namespace std;

GPIO *outGPIO, *inGPIO; // global pointers

int toggleLED(int var){ // the callback function
	if(outGPIO->getValue() == 1){
		outGPIO->streamWrite(GPIO::LOW); 
	}else
		outGPIO->streamWrite(GPIO::HIGH);
return 0;
}
int main(){

	outGPIO = new GPIO(49);
	inGPIO = new GPIO(115);
	inGPIO->setDirection(GPIO::INPUT);
	outGPIO->setDirection(GPIO::OUTPUT);
		outGPIO->streamOpen(); 
			inGPIO->setEdgeType(GPIO::RISING);
			inGPIO->waitForEdge(&toggleLED);
			usleep(50000000);
		outGPIO->streamClose();
return 0;
}
