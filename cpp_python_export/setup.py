from setuptools import setup, Extension
import pybind11

cpp_args = ['-std=c++11']

cp_mat = Extension(
    'compute_mat',
    sources=['python_export.cpp',
             '../compute_mat.c',
             'cpp_wrappers/compute_mat_wrapper.cpp'
             ],
    include_dirs=[pybind11.get_include(), '../..', 'cpp_wrappers', '..'],
    language='c++',
    extra_compile_args=cpp_args,
    )

setup(
    name='compute_mat',
    version='1.0',
    description='great description here for compute mat',
    ext_modules=[cp_mat],
)
