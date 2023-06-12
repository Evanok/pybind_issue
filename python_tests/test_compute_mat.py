import compute_mat as cm
import numpy as np
from scipy import signal as sp
import matplotlib.pyplot as plt
import pytest
import os
import time

def load_and_run_mat():
        input_size = 56
        mat = cm.compute_mat ()
        print ('init...')

        print ("pid", os.getpid())
        time.sleep(0)
        mat.compute_mat_wrapper_create (input_size)
        print ("create done..")
        c_output = np.zeros ((input_size,), dtype=np.float32)
        temp_r = np.zeros ((input_size,), dtype=np.float32)
        temp_z = np.zeros ((input_size,), dtype=np.float32)


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
        mat.compute_mat_wrapper_prepare(temp_r, temp_z,
                                        b_hn, b_in,
                                        b_r, b_z,
                                        W_hn, W_hr, W_hz,
                                        W_in, W_ir, W_iz)
        print ("process..")
        c_output = mat.compute_mat_wrapper_process(c_input, c_output)
        mat.compute_mat_wrapper_destroy()


if __name__ == "__main__":
    load_and_run_mat ()
