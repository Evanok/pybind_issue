#ifndef __compute_mat_h
#define __compute_mat_h

#ifdef __cplusplus
extern "C" {
#endif

#include <math.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

	typedef struct
	{
		uint32_t nb;

		const float* b_in;
		const float* b_hn;
		const float* b_r;
		const float* b_z;
		const float* W_hn;
		const float* W_hr;
		const float* W_hz;
		const float* W_in;
		const float* W_ir;
		const float* W_iz;

		float* temp_r;
		float* temp_z;

		float* state;

	} compute_mat_struct;

	void compute_mat_create(compute_mat_struct* p_this, uint32_t nb);
	void compute_mat_prepare(compute_mat_struct* p_this,
		float* temp_r, float* temp_z,
		const float* b_hn, const float* b_in,
		const float* b_r, const float* b_z,
		const float* W_hn, const float* W_hr, const float* W_hz,
		const float* W_in, const float* W_ir, const float* W_iz);
	void compute_mat_process(compute_mat_struct* p_this, float* input, float* output);
	void compute_mat_destroy(compute_mat_struct* p_this);


#ifdef __cplusplus
}
#endif

#endif
