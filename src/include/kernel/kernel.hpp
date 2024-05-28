#ifndef KERNEL_H
#define KERNEL_H

#include <iostream>
#include <vector>

#include "../bayesian_types.hpp"
#include "kernel_functions.hpp"
#include "kernel_types.hpp"

using std::vector;

void kernel_column_vector_and_conv_vector(kernel_vec &ker_vec, kernel_vec &conv_vec, const int index, kernel_array &kernel,
                                          kernel_array &conv_kernel,
                                          const int num_obs);

void create_kernel_and_coeff_C_Plus(kernel_array &k, Eigen::Ref<compatible_storage_order_matrix> &dataset_x,
                                    Eigen::Ref<kernel_vec> &time_vec,
                                    KernelParams &kernel_space, KernelParams &kernel_time,
                                    kernel_array &coeff_c_plus, const int d, const double t0, const int num_obs,
                                    const double lambda);

void create_kernel_tilde_and_C_plus(kernel_array &matrix_kernel, int index, kernel_array &result_kernel,
                                    kernel_array &c_plus, kernel_array &result_c_plus,
                                    const int num_obs);

void create_y_vector_tilde(Eigen::Ref<kernel_vec> &y_vec, int index, kernel_vec &result,
                           const int num_obs);

int E_sub_product(kernel_array &kernel_tilde,
                  kernel_vec &vec, double &result);

int G_sub_product(kernel_array &kernel_tilde,
                  kernel_vec &vec,
                  kernel_row_vec &result);

int normalization_criterion_sub_product(kernel_array &matrix, Eigen::Ref<kernel_vec> &vec, kernel_vec &result);

#endif