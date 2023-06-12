#include "compute_mat_wrapper.h"

compute_mat_wrapper::compute_mat_wrapper()
    :_params_c()
{
}

compute_mat_wrapper::~compute_mat_wrapper()
{
}

void compute_mat_wrapper::compute_mat_wrapper_create(uint32_t nb)
{
    printf ("lets create with nb %d\n", nb);
    compute_mat_create(&_params_c, nb);
    printf ("create done..\n");
}

void compute_mat_wrapper::compute_mat_wrapper_prepare(float* temp_r, float* temp_z,
    const float* b_hn, const float* b_in,
    const float* b_r, const float* b_z,
    const float* W_hn, const float* W_hr, const float* W_hz,
    const float* W_in, const float* W_ir, const float* W_iz)
{
    compute_mat_prepare(&_params_c,
        temp_r, temp_z,
        b_hn, b_in,
        b_r, b_z,
        W_hn, W_hr, W_hz,
        W_in, W_ir, W_iz);
}

void compute_mat_wrapper::compute_mat_wrapper_process(float* input, float* output)
{
    compute_mat_process(&_params_c, input, output);
}

void compute_mat_wrapper::compute_mat_wrapper_destroy(void)
{
    compute_mat_destroy(&_params_c);
}
