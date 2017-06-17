//============================================================================
// Name        : main.cpp
// Author      : Volkan Kumbasar
// Version     :
// Copyright   :
// Description : BPSK in AWGN channel simulation
//============================================================================

#include <iostream>
#include "CommLib.h"

int main() {

	const int SNR_MIN = 0; //min SNR
	const int SNR_MAX = 15; //max SNR
	const int BIT_SIZE = 1000000; //total bits

	//bit error rate
	double *pBER = new double[ SNR_MAX - SNR_MIN + 1 ];
	//noise array
	double *noise;
	//bit array
	bool *bit;

	bool decod_bit;
	double s_signal;

	for(int snr_dB = SNR_MIN ; snr_dB <= SNR_MAX ; ++snr_dB) {

	  std::cout << "SNR = " << snr_dB << std::endl;

	  noise = CommLib::gauss( CommLib::noiseSigma(snr_dB) , BIT_SIZE);
	  bit = CommLib::bitGenerator(BIT_SIZE);

	  for(int i = 0 ; i < BIT_SIZE ; ++i) {

	  	s_signal = CommLib::bpskMod( bit[i] );

	  	decod_bit =  CommLib::bpskDeMod(s_signal + noise[i]);

	  	//std::cout << (s_signal + noise[i]) << " " <<  noise[i] << "\n";

	  	if ( decod_bit != bit[i] ) {
	  		++pBER[snr_dB];
	  		//std::cout << pBER[snr_dB] << "\n";
	  	}
	  }
	}

	std::cout << "Pber = [ ";
	for(int i = 0 ; i < SNR_MAX - SNR_MIN + 1; ++i) {
		std::cout << pBER[i]/BIT_SIZE << " ";
	}
	std::cout << " ]" << std::endl;

	delete[] noise;
	delete[] bit;
	delete[] pBER;
}

