#include "compute_mat.h"

// ------------------------------------------------------------------------------------------------
//
// ------------------------------------------------------------------------------------------------
void compute_mat_create(compute_mat_struct* p_this, uint32_t nb)
{
	printf ("%s\n", __FUNCTION__);
	p_this->nb = nb;
	printf ("nb is %d\n ", p_this->nb);
	printf ("pre malloc %p...\n", p_this->state);
	p_this->state = (float*) malloc(sizeof(float) * nb);
	if (p_this->state == NULL)
	{
		printf ("Cannot alloc state\n");
	}
	printf ("malloc done %p...\n", p_this->state);

	memset(p_this->state, 0, sizeof(float) * nb); // -> SEGMENTATION FAULT
	printf ("%s DONE\n", __FUNCTION__);
}

void compute_mat_prepare(compute_mat_struct* p_this,
	float* temp_r, float* temp_z,
	const float* b_hn, const float* b_in,
	const float* b_r, const float* b_z,
	const float* W_hn, const float* W_hr, const float* W_hz,
	const float* W_in, const float* W_ir, const float* W_iz)
{
	p_this->temp_r = temp_r;
	p_this->temp_z = temp_z;

	p_this->b_z = b_z;
	p_this->b_in = b_in;
	p_this->b_hn = b_hn;
	p_this->b_r = b_r;
	p_this->W_hn = W_hn;
	p_this->W_hr = W_hr;
	p_this->W_hz = W_hz;
	p_this->W_in = W_in;
	p_this->W_ir = W_ir;
	p_this->W_iz = W_iz;

}

void compute_mat_process(compute_mat_struct* p_this, float* input, float* output)
{
	float sum = 0.0;
	for (uint32_t k = 0; k < p_this->nb; k++)
	{
		sum = p_this->b_r[k] + p_this->W_ir[k] - p_this->b_hn[k] - input[k] + p_this->W_in[k];
		output[k] = (1 - p_this->temp_z[k]) * sum + (p_this->temp_z[k]);

		p_this->state[k] = output[k];
	}
}

void compute_mat_destroy(compute_mat_struct* p_this)
{
	free(p_this->state);
}
