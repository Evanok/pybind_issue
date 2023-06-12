#pragma once

#include "compute_mat.h"
#include <stdint.h>
#include <stdio.h>

class compute_mat_wrapper
{
public:
	compute_mat_wrapper();
	~compute_mat_wrapper();
	void compute_mat_wrapper_create(uint32_t nb);
	void compute_mat_wrapper_prepare(float* temp_r, float* temp_z,
		const float* b_hn, const float* b_in,
		const float* b_r, const float* b_z,
		const float* W_hn, const float* W_hr, const float* W_hz,
		const float* W_in, const float* W_ir, const float* W_iz);
	void compute_mat_wrapper_process(float* input, float* output);
	void compute_mat_wrapper_destroy(void);

private:
	compute_mat_struct _params_c;
};
