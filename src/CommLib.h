#ifndef COMMLIB_H_
#define COMMLIB_H_

#include <cmath>

#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

namespace CommLib {
	
	double * gauss(double sigma , long size){
		/*?*/
		
		double * rtn = new double[size];
				
		const gsl_rng_type * T;
		gsl_rng * r;
		
		gsl_rng_env_setup();

 	 	T = gsl_rng_default;
  		r = gsl_rng_alloc (T);
		
		for (int i = 0; i < size; ++i)  {
			
			rtn[i] = gsl_ran_gaussian (r, sigma);
   		}
   		
   		return rtn;
	};
	
	bool * bitGenerator(long size){
		
		bool * rtn = new bool[size];
				
		const gsl_rng_type * T;
		gsl_rng * r;
		
		gsl_rng_env_setup();

 	 	T = gsl_rng_default;
  		r = gsl_rng_alloc (T);
		
		for (int i = 0; i < size; ++i)  {
			rtn[i] = gsl_rng_uniform (r) >= 0.5 ? true:false;
   		}
   		
   		return rtn;
	};
	
	inline double bpskMod(bool bit , double Eb = 1.0){
		return bit ? Eb:-Eb;
	};
	
	inline bool bpskDeMod(double signal){
		return signal >= 0 ? true:false;
	};
	
	double noiseSigma(double igo_dB , double Eb = 1.0) {
		return sqrt(0.5 * Eb * pow(10.0 , -igo_dB*0.1));
	};
	
}
#endif /*COMMLIB_H_*/
