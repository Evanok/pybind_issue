
// Add system headers here
#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>
#include "cpp_wrappers/compute_mat_wrapper.h"

namespace py = pybind11;


PYBIND11_MODULE(compute_mat, m)
{ 
    py::class_<compute_mat_wrapper>(m, "compute_mat")
        .def(py::init<>())
        .def("compute_mat_wrapper_create", [](compute_mat_wrapper& skr, uint32_t nb) {
                skr.compute_mat_wrapper_create(nb);
            })
        .def("compute_mat_wrapper_prepare", [](compute_mat_wrapper& skr,
            std::vector<float> b_hn, std::vector<float> b_in,
            std::vector<float> b_r, std::vector<float> b_z,
            std::vector<float> W_hn, std::vector<float> W_hr, std::vector<float> W_hz,
            std::vector<float> W_in, std::vector<float> W_ir, std::vector<float> W_iz) {
                skr.compute_mat_wrapper_prepare(
                    b_hn.data(), b_in.data(),
                    b_r.data(), b_z.data(),
                    W_hn.data(), W_hr.data(), W_hz.data(),
                    W_in.data(), W_ir.data(), W_iz.data());
            })
        .def("compute_mat_wrapper_process", [](compute_mat_wrapper& skr,
            std::vector<float> input, std::vector<float> output) {
                skr.compute_mat_wrapper_process(input.data(), output.data());
                return output;
            })
        .def("compute_mat_wrapper_destroy", [](compute_mat_wrapper& skr) {
                skr.compute_mat_wrapper_destroy();
            });
}
