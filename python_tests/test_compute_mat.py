import compute_mat as cm
import numpy as np

def compute_mat (nb, input,
    b_hn, b_in,
    b_r, b_z,
    W_hn, W_hr, W_hz,
    W_in, W_ir, W_iz):
    
    output = [0 for i in range(nb)]
    print ("input", input)

    sum = 0.0;
    for k in range(nb):
        sum = b_r[k] + W_ir[k] - b_hn[k] - input[k] + W_in[k]
        output[k] = sum
    return output

def load_and_run_mat():
    input_size = 56
    mat = cm.compute_mat ()
    print ('init...')

    mat.compute_mat_wrapper_create (input_size)
    print ("create done..")
    c_output = np.zeros ((input_size,), dtype=np.float32)
    python_output = np.zeros ((input_size,), dtype=np.float32)


    c_input = [0 for i in range(input_size)]

    b_hn = np.random.uniform(low=0.0, high=1.0, size=(input_size,))
    b_in = np.random.uniform(low=0.0, high=1.0, size=(input_size,))
    b_r = np.random.uniform(low=0.0, high=1.0, size=(input_size,))
    b_z = np.random.uniform(low=0.0, high=1.0, size=(input_size,))

    W_hn = np.random.uniform(low=0.0, high=1.0, size=(input_size,))
    W_hr = np.random.uniform(low=0.0, high=1.0, size=(input_size,))
    W_hz = np.random.uniform(low=0.0, high=1.0, size=(input_size,))
    W_in = np.random.uniform(low=0.0, high=1.0, size=(input_size,))
    W_ir = np.random.uniform(low=0.0, high=1.0, size=(input_size,))
    W_iz = np.random.uniform(low=0.0, high=1.0, size=(input_size,))

    print ("b_r", b_r)

    for index in range(0, input_size):
        c_input[index] = 1.0 * index
    print ('prepare..')
    mat.compute_mat_wrapper_prepare(b_hn, b_in,
                                    b_r, b_z,
                                    W_hn, W_hr, W_hz,
                                    W_in, W_ir, W_iz)
    print ("process..")
    c_output = mat.compute_mat_wrapper_process(c_input, c_output)
    mat.compute_mat_wrapper_destroy()

    print ("input", c_input)
    python_output = compute_mat (input_size, c_input,
        b_hn, b_in,
        b_r, b_z,
        W_hn, W_hr, W_hz,
        W_in, W_ir, W_iz)

    max_error = 0.0
    total_value = 0
    total_error = 0
    for band in range(0, input_size):
        v1 = c_output[band]
        v2 = python_output[band]
        error = abs(v1 - v2)
        if (error > max_error): max_error = error
        if error > 1e-04:
            total_error = total_error + 1
        total_value = total_value + 1

    if total_error > 0:
        print("Failed. Total value: ", total_value, ", total error: ", total_error)
        return 1
    else:
        print("Success. Max error: " + str(max_error))
        return 0


    print ("all done")


if __name__ == "__main__":
    load_and_run_mat ()
